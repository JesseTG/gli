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
/// @file gli/test/core_load_dds.hpp
/// @date 2013-03-12 / 2013-03-12
/// @author Christophe Riccio
///////////////////////////////////////////////////////////////////////////////////

#include <gli/gli.hpp>

int test_texture2d_export_dds()
{
	int Error(0);

	{
		gli::texture2D Texture(gli::loadStorageDDS("../../data/test_rgb8.dds"));
		assert(!Texture.empty());
		gli::saveStorageDDS(Texture, "../../data/test_rgb8_saved.dds");
	}
	{
		gli::texture2D Texture(gli::loadStorageDDS("../../data/test_rgb8_saved.dds"));
		assert(!Texture.empty());
		gli::saveStorageDDS(Texture, "../../data/test_rgb8_reloaded.dds");
	}
	{
		gli::texture2D Texture(gli::loadStorageDDS("../../data/test_dxt1.dds"));
		assert(!Texture.empty());
		gli::saveStorageDDS(Texture, "../../data/test_dxt1_saved.dds");
	}
	{
		gli::texture2D Texture(gli::loadStorageDDS("../../data/test_bc1.dds"));
		assert(!Texture.empty());
		gli::saveStorageDDS(Texture, "../../data/test_bc1_saved.dds");
	}

	return Error;
}

int test_texture2d()
{
	int Error(0);

	{
		gli::texture2D Texture(
			gli::texture2D::size_type(1), 
			gli::RGBA8_UNORM, 
			gli::texture2D::dimensions_type(256));

		for(gli::texture2D::size_type TexelIndex = 0; TexelIndex < Texture.size<glm::u8vec4>(); ++TexelIndex)
			*(Texture.data<glm::u8vec4>() + TexelIndex) = glm::u8vec4(255, 128, 0, 255);

		gli::saveStorageDDS(Texture, "../../data/texture2D_1level_rgba8_unorm_256.dds");
	}

	{
		gli::texture2D Texture(
			gli::texture2D::size_type(1), 
			gli::RGBA16_UNORM, 
			gli::texture2D::dimensions_type(256));

		for(gli::texture2D::size_type TexelIndex = 0; TexelIndex < Texture.size<glm::u16vec4>(); ++TexelIndex)
			*(Texture.data<glm::u16vec4>() + TexelIndex) = glm::u16vec4(65535, 32768, 0, 65535);

		gli::saveStorageDDS(Texture, "../../data/texture2D_1level_rgba16_unorm_256.dds");
	}

	{
		gli::texture2D Texture(
			gli::texture2D::size_type(glm::log2(256.f)), 
			gli::RGBA8_UNORM, 
			gli::texture2D::dimensions_type(256));

		for(gli::texture2D::size_type TexelIndex = 0; TexelIndex < Texture.size<glm::u8vec4>(); ++TexelIndex)
			*(Texture.data<glm::u8vec4>() + TexelIndex) = glm::u8vec4(255, 128, 0, 255);

		gli::saveStorageDDS(Texture, "../../data/texture2D_mipmaps_rgba8_unorm_256.dds");
	}

	{
		gli::texture2D Texture(
			gli::texture2D::size_type(glm::log2(256.f)), 
			gli::RGBA16_UNORM, 
			gli::texture2D::dimensions_type(256));

		for(gli::texture2D::size_type TexelIndex = 0; TexelIndex < Texture.size<glm::u16vec4>(); ++TexelIndex)
			*(Texture.data<glm::u16vec4>() + TexelIndex) = glm::u16vec4(65535, 32768, 0, 65535);

		gli::saveStorageDDS(Texture, "../../data/texture2D_mipmaps_rgba16_unorm_256.dds");
	}

	return 0;
}

int test_texture2DArray()
{
	int Error(0);

	{
		gli::texture2DArray Texture(
			gli::texture2D::size_type(2), 
			gli::texture2D::size_type(1), 
			gli::RGBA8_UNORM, 
			gli::texture2D::dimensions_type(8));

		std::vector<glm::u8vec4> Color;
		Color.push_back(glm::u8vec4(255, 128,   0, 255));
		Color.push_back(glm::u8vec4(  0, 128, 255, 255));

		for(gli::texture2DArray::size_type LayerIndex = 0; LayerIndex < Texture.layers(); ++LayerIndex)
		for(gli::texture2D::size_type TexelIndex = 0; TexelIndex < Texture[LayerIndex].size<glm::u8vec4>(); ++TexelIndex)
			*(Texture[LayerIndex].data<glm::u8vec4>() + TexelIndex) = Color[LayerIndex];

		gli::saveStorageDDS(Texture, "../../data/texture2DArray_rgba8u_256.dds");
	}

	{
		gli::texture2D TextureA(gli::loadStorageDDS("../../data/test-rgb8-256a.dds"));
		gli::texture2D TextureB(gli::loadStorageDDS("../../data/test-rgb8-256b.dds"));

		assert(TextureA.format() == TextureB.format());
		assert(glm::all(glm::equal(TextureA.dimensions(), TextureB.dimensions())));

		gli::texture2DArray Texture(
			gli::texture2D::size_type(2), 
			TextureA.levels(), 
			TextureA.format(), 
			TextureA.dimensions());

		memcpy(Texture[0].data(), TextureA.data(), TextureA.size());
		memcpy(Texture[1].data(), TextureB.data(), TextureB.size());

		gli::texture2D Texture0 = gli::copy(Texture[0]);
		gli::texture2D Texture1 = gli::copy(Texture[1]);

		gli::saveStorageDDS(Texture0, "../../data/test-rgb8-256-layer0-saved.dds");
		gli::saveStorageDDS(Texture1, "../../data/test-rgb8-256-layer1-saved.dds");
		gli::saveStorageDDS(Texture, "../../data/test-rgb8-256-array-saved.dds");
	}

	{
		gli::texture2DArray Texture(gli::loadStorageDDS("../../data/test-rgb8-256-array-saved.dds"));
		assert(!Texture.empty());
	}

	return 0;
}

int test_textureCube()
{
	int Error(0);

	{
		gli::textureCube Texture(
			gli::textureCube::size_type(6),
			gli::textureCube::size_type(1), 
			gli::RGBA8_UNORM, 
			gli::textureCube::dimensions_type(256));

		std::vector<glm::u8vec4> Color;
		Color.push_back(glm::u8vec4(255,   0,   0, 255));
		Color.push_back(glm::u8vec4(255, 128,   0, 255));
		Color.push_back(glm::u8vec4(255, 255,   0, 255));
		Color.push_back(glm::u8vec4(  0, 255,   0, 255));
		Color.push_back(glm::u8vec4(  0, 128, 255, 255));
		Color.push_back(glm::u8vec4(  0,   0, 255, 255));

		for(gli::textureCube::size_type FaceIndex = 0; FaceIndex < Texture.faces(); ++FaceIndex)
		for(gli::texture2D::size_type TexelIndex = 0; TexelIndex < Texture[FaceIndex].size<glm::u8vec4>(); ++TexelIndex)
			*(Texture[FaceIndex].data<glm::u8vec4>() + TexelIndex) = Color[FaceIndex];

		gli::saveStorageDDS(Texture, "../../data/textureCube_rgba8u_256.dds");
	}

	{
		gli::textureCube Texture(gli::loadStorageDDS("../../data/cube.dds"));
		gli::saveStorageDDS(Texture, "../../data/cube_saved.dds");
	}

	{
		gli::textureCube Texture(gli::loadStorageDDS("../../data/cube_saved.dds"));
	}

	return 0;
}

int main()
{
	int Error(0);

	Error += test_texture2d_export_dds();
	Error += test_texture2d();
	Error += test_texture2DArray();
	Error += test_textureCube();

	return Error;
}

