///////////////////////////////////////////////////////////////////////////////////
/// OpenGL Image (gli.g-truc.net)
///
/// Copyright (c) 2008 - 2013 G-Truc Creation (www.g-truc.net)
/// Permission is hereby granted, free of charge, to any person obtaining a copy
/// of this software and associated documentation files (the "Software"), to deal
/// in the Software without restriction, including without limitation the rights
/// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
/// copies of the Software, and to permit persons to whom the Software is
/// furnished to do so, subject to the following conditions:
/// 
/// The above copyright notice and this permission notice shall be included in
/// all copies or substantial portions of the Software.
/// 
/// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
/// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
/// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
/// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
/// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
/// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
/// THE SOFTWARE.
///
/// @ref core
/// @file gli/core/view.hpp
/// @date 2013-02-03 / 2013-02-03
/// @author Christophe Riccio
///////////////////////////////////////////////////////////////////////////////////

#ifndef GLI_CORE_VIEW_INCLUDED
#define GLI_CORE_VIEW_INCLUDED

#include "texture1d.hpp"
#include "texture1d_array.hpp"
#include "texture2d.hpp"
#include "texture2d_array.hpp"
#include "texture3d.hpp"
#include "texture_cube.hpp"
#include "texture_cube_array.hpp"

namespace gli
{
	template <typename texture>
	texture1D view1D(
		texture const & Texture,
		typename texture::format_type const & Format,
		typename texture::size_type const & BaseLayer,
		typename texture::size_type const & BaseFace,
		typename texture::size_type const & BaseLevel,
		typename texture::size_type const & MaxLevel);

	template <typename texture>
	texture1DArray view1DArray(
		texture const & Texture,
		typename texture::format_type const & Format,
		typename texture::size_type const & BaseLayer,
		typename texture::size_type const & MaxLayer,
		typename texture::size_type const & BaseFace,
		typename texture::size_type const & BaseLevel,
		typename texture::size_type const & MaxLevel);

	template <typename texture>
	texture2D view2D(
		texture const & Texture,
		typename texture::format_type const & Format,
		typename texture::size_type const & BaseLayer,
		typename texture::size_type const & BaseFace,
		typename texture::size_type const & BaseLevel,
		typename texture::size_type const & MaxLevel);

	template <typename texture>
	texture2DArray view2DArray(
		texture const & Texture,
		typename texture::format_type const & Format,
		typename texture::size_type const & BaseLayer,
		typename texture::size_type const & MaxLayer,
		typename texture::size_type const & BaseFace,
		typename texture::size_type const & BaseLevel,
		typename texture::size_type const & MaxLevel);

	template <typename texture>
	texture3D view3D(
		texture const & Texture,
		typename texture::format_type const & Format,
		typename texture::size_type const & BaseLayer,
		typename texture::size_type const & BaseFace,
		typename texture::size_type const & BaseLevel,
		typename texture::size_type const & MaxLevel);

	template <typename texture>
	textureCube viewCube(
		texture const & Texture,
		typename texture::format_type const & Format,
		typename texture::size_type const & BaseLayer,
		typename texture::size_type const & BaseFace,
		typename texture::size_type const & MaxFace,
		typename texture::size_type const & BaseLevel,
		typename texture::size_type const & MaxLevel);

	template <typename texture>
	textureCubeArray viewCubeArray(
		texture const & Texture,
		typename texture::format_type const & Format,
		typename texture::size_type const & BaseLayer,
		typename texture::size_type const & MaxLayer,
		typename texture::size_type const & BaseFace,
		typename texture::size_type const & MaxFace,
		typename texture::size_type const & BaseLevel,
		typename texture::size_type const & MaxLevel);
}//namespace

#include "view.inl"

#endif//GLI_CORE_VIEW_INCLUDED