/*
This file belongs to Renderer.
See LICENSE file in root folder.
*/
#pragma once

#include <Utils/PixelFormat.hpp>

namespace gl_renderer
{
	/**
	*\brief
	*	R�cup�re le format interne OpenGL pour le utils::PixelFormat donn�.
	*\param[in] format
	*	Le utils::PixelFormat.
	*\return
	*	Le format interne OpenGL.
	*/
	GLenum getInternal( utils::PixelFormat const & format )noexcept;
	/**
	*\brief
	*	R�cup�re le format OpenGL pour le utils::PixelFormat donn�.
	*\param[in] format
	*	Le utils::PixelFormat.
	*\return
	*	Le format OpenGL.
	*/
	GLenum getFormat( utils::PixelFormat format )noexcept;
	/**
	*\brief
	*	R�cup�re le type de donn�es OpenGL pour le utils::PixelFormat donn�.
	*\param[in] format
	*	Le utils::PixelFormat.
	*\return
	*	Le type de donn�es OpenGL.
	*/
	GLenum getType( utils::PixelFormat format )noexcept;
	/**
	*\brief
	*	R�cup�re le taille des donn�es pour le utils::PixelFormat donn�.
	*\param[in] format
	*	Le utils::PixelFormat.
	*\return
	*	La taille des donn�es.
	*/
	uint32_t getSize( utils::PixelFormat format )noexcept;
	/**
	*\brief
	*	Convertit un VkFormat en utils::PixelFormat.
	*\param[in] format
	*	Le VkFormat.
	*\return
	*	Le utils::PixelFormat.
	*/
	utils::PixelFormat convert( GLenum format )noexcept;
}
