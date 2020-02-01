/*
This file belongs to Ashes.
See LICENSE file in root folder.
*/
#include "Core/D3D11Layer.hpp"

#include <iostream>

namespace ashes::d3d11
{
	bool Layer::bufferImageCommand( VkCommandBuffer cmd
		, VkBufferImageCopy const & copyInfo
		, VkBuffer buffer
		, VkImage image )const try
	{
		return onBufferImageCommand( cmd
			, copyInfo
			, buffer
			, image );
	}
	catch ( LayerException & exc )
	{
		std::cerr << "Layer Exception " << exc.what() << std::endl;
		return false;
	}
	catch ( std::exception & exc )
	{
		std::cerr << "Std Exception " << exc.what() << std::endl;
		return false;
	}
	catch ( ... )
	{
		std::cerr << "Unknown Exception" << std::endl;
		return false;
	}

	bool Layer::copyToImageCommand( VkCommandBuffer cmd
		, ArrayView< VkBufferImageCopy const > const & copyInfo
		, VkBuffer src
		, VkImage dst )const try
	{
		return onCopyToImageCommand( cmd
			, copyInfo
			, src
			, dst );
	}
	catch ( LayerException & exc )
	{
		std::cerr << "Layer Exception " << exc.what() << std::endl;
		return false;
	}
	catch ( std::exception & exc )
	{
		std::cerr << "Std Exception " << exc.what() << std::endl;
		return false;
	}
	catch ( ... )
	{
		std::cerr << "Unknown Exception" << std::endl;
		return false;
	}

	bool Layer::checkHResultCommand( HRESULT hresult
		, std::string message )const try
	{
		return onCheckHResultCommand( hresult
			, message );
	}
	catch ( LayerException & /*exc*/ )
	{
		throw;
	}
	catch ( std::exception & exc )
	{
		std::cerr << "Std Exception " << exc.what() << std::endl;
		return false;
	}
	catch ( ... )
	{
		std::cerr << "Unknown Exception" << std::endl;
		return false;
	}

#if VK_EXT_debug_utils

	void Layer::submitDebugUtilsMessenger( VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity
		, VkDebugUtilsMessageTypeFlagsEXT messageTypes
		, VkDebugUtilsMessengerCallbackDataEXT const & callbackData )const try
	{
		onSubmitDebugUtilsMessenger( messageSeverity
			, messageTypes
			, callbackData );
	}
	catch ( LayerException & exc )
	{
		std::cerr << "Layer Exception " << exc.what() << std::endl;
	}
	catch ( std::exception & exc )
	{
		std::cerr << "Std Exception " << exc.what() << std::endl;
	}
	catch ( ... )
	{
		std::cerr << "Unknown Exception" << std::endl;
	}

#endif
#if VK_EXT_debug_report

	void Layer::reportMessage( VkDebugReportFlagsEXT flags
		, VkDebugReportObjectTypeEXT objectType
		, uint64_t object
		, size_t location
		, int32_t messageCode
		, const char * pLayerPrefix
		, const char * pMessage )const try
	{
		return onReportMessage( flags
			, objectType
			, object
			, location
			, messageCode
			, pLayerPrefix
			, pMessage );
	}
	catch ( LayerException & exc )
	{
		std::cerr << "Layer Exception " << exc.what() << std::endl;
	}
	catch ( std::exception & exc )
	{
		std::cerr << "Std Exception " << exc.what() << std::endl;
	}
	catch ( ... )
	{
		std::cerr << "Unknown Exception" << std::endl;
	}

#endif
}
