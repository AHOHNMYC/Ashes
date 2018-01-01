/*
This file belongs to Renderer.
See LICENSE file in root folder.
*/
#pragma once

#include <Renderer/AttributeFormat.hpp>

namespace gl_renderer
{
	/**
	*\brief
	*	Convertit un renderer::AttributeFormat en VkFormat.
	*\param[in] flags
	*	Le renderer::AttributeFormat.
	*\return
	*	Le VkFormat.
	*/
	GLenum convert( renderer::AttributeFormat format );
	/**
	*\brief
	*	R�cup�re la taille en octets du format donn�.
	*\param[in] flags
	*	Le renderer::AttributeFormat.
	*\return
	*	La taille.
	*/
	uint32_t getSize( renderer::AttributeFormat format );
}
