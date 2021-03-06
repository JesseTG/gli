#include <gli/gl.hpp>
#include <gli/texture2d.hpp>

namespace ktx
{
	int run()
	{
		int Error = 0;

		gli::gl GL(gli::gl::PROFILE_KTX);

		gli::texture2d TextureA(gli::FORMAT_RGB8_UNORM_PACK8, gli::texture2d::extent_type(2), 1, gli::texture2d::swizzles_type(gli::SWIZZLE_RED, gli::SWIZZLE_GREEN, gli::SWIZZLE_BLUE, gli::SWIZZLE_ALPHA));
		gli::gl::format FormatA = GL.translate(TextureA.format(), TextureA.swizzles());

		Error += FormatA.Internal == gli::gl::INTERNAL_RGB8_UNORM ? 0 : 1;
		Error += FormatA.External == gli::gl::EXTERNAL_RGB ? 0 : 1;
		Error += FormatA.Type == gli::gl::TYPE_U8 ? 0 : 1;
		Error += FormatA.Swizzles == gli::gl::swizzles(gli::gl::SWIZZLE_RED, gli::gl::SWIZZLE_GREEN, gli::gl::SWIZZLE_BLUE, gli::gl::SWIZZLE_ONE) ? 0 : 1;

		gli::texture2d TextureB(gli::FORMAT_BGR8_UNORM_PACK8, gli::texture2d::extent_type(2), 1, gli::texture2d::swizzles_type(gli::SWIZZLE_RED, gli::SWIZZLE_GREEN, gli::SWIZZLE_BLUE, gli::SWIZZLE_ALPHA));
		gli::gl::format FormatB = GL.translate(TextureB.format(), TextureB.swizzles());

		Error += FormatB.Internal == gli::gl::INTERNAL_RGB8_UNORM ? 0 : 1;
		Error += FormatB.External == gli::gl::EXTERNAL_BGR ? 0 : 1;
		Error += FormatB.Type == gli::gl::TYPE_U8 ? 0 : 1;
		Error += FormatB.Swizzles == gli::gl::swizzles(gli::gl::SWIZZLE_RED, gli::gl::SWIZZLE_GREEN, gli::gl::SWIZZLE_BLUE, gli::gl::SWIZZLE_ONE) ? 0 : 1;

		return Error;
	}
}//namespace ktx

namespace gl32
{
	int run()
	{
		int Error = 0;

		gli::gl GL(gli::gl::PROFILE_GL32);

		gli::texture2d TextureA(gli::FORMAT_RGB8_UNORM_PACK8, gli::texture2d::extent_type(2), 1, gli::texture2d::swizzles_type(gli::SWIZZLE_RED, gli::SWIZZLE_GREEN, gli::SWIZZLE_BLUE, gli::SWIZZLE_ALPHA));
		gli::gl::format FormatA = GL.translate(TextureA.format(), TextureA.swizzles());

		Error += FormatA.Internal == gli::gl::INTERNAL_RGB8_UNORM ? 0 : 1;
		Error += FormatA.External == gli::gl::EXTERNAL_RGB ? 0 : 1;
		Error += FormatA.Type == gli::gl::TYPE_U8 ? 0 : 1;
		Error += FormatA.Swizzles == gli::gl::swizzles(gli::gl::SWIZZLE_RED, gli::gl::SWIZZLE_GREEN, gli::gl::SWIZZLE_BLUE, gli::gl::SWIZZLE_ONE) ? 0 : 1;

		gli::texture2d TextureB(gli::FORMAT_BGR8_UNORM_PACK8, gli::texture2d::extent_type(2), 1, gli::texture2d::swizzles_type(gli::SWIZZLE_RED, gli::SWIZZLE_GREEN, gli::SWIZZLE_BLUE, gli::SWIZZLE_ALPHA));
		gli::gl::format FormatB = GL.translate(TextureB.format(), TextureB.swizzles());

		Error += FormatB.Internal == gli::gl::INTERNAL_RGB8_UNORM ? 0 : 1;
		Error += FormatB.External == gli::gl::EXTERNAL_BGR ? 0 : 1;
		Error += FormatB.Type == gli::gl::TYPE_U8 ? 0 : 1;
		Error += FormatB.Swizzles == gli::gl::swizzles(gli::gl::SWIZZLE_RED, gli::gl::SWIZZLE_GREEN, gli::gl::SWIZZLE_BLUE, gli::gl::SWIZZLE_ONE) ? 0 : 1;

		{
			gli::texture2d TextureC(gli::FORMAT_R5G6B5_UNORM_PACK16, gli::texture2d::extent_type(2), 1, gli::texture2d::swizzles_type(gli::SWIZZLE_RED, gli::SWIZZLE_GREEN, gli::SWIZZLE_BLUE, gli::SWIZZLE_ALPHA));
			gli::gl::format FormatC = GL.translate(TextureC.format(), TextureC.swizzles());

			Error += FormatC.Internal == gli::gl::INTERNAL_R5G6B5 ? 0 : 1;
			Error += FormatC.External == gli::gl::EXTERNAL_RGB ? 0 : 1;
			Error += FormatC.Type == gli::gl::TYPE_UINT16_R5G6B5_REV ? 0 : 1;
			Error += FormatC.Swizzles == gli::gl::swizzles(gli::gl::SWIZZLE_RED, gli::gl::SWIZZLE_GREEN, gli::gl::SWIZZLE_BLUE, gli::gl::SWIZZLE_ONE) ? 0 : 1;

			gli::format FormatD2 = GL.find(FormatC.Internal, FormatC.External, FormatC.Type);
			Error += FormatD2 == TextureC.format() ? 0 : 1;
		}

		{
			gli::texture2d TextureD(gli::FORMAT_B5G6R5_UNORM_PACK16, gli::texture2d::extent_type(2), 1, gli::texture2d::swizzles_type(gli::SWIZZLE_RED, gli::SWIZZLE_GREEN, gli::SWIZZLE_BLUE, gli::SWIZZLE_ALPHA));
			gli::gl::format FormatD = GL.translate(TextureD.format(), TextureD.swizzles());

			Error += FormatD.Internal == gli::gl::INTERNAL_R5G6B5 ? 0 : 1;
			Error += FormatD.External == gli::gl::EXTERNAL_RGB ? 0 : 1;
			Error += FormatD.Type == gli::gl::TYPE_UINT16_R5G6B5 ? 0 : 1;
			Error += FormatD.Swizzles == gli::gl::swizzles(gli::gl::SWIZZLE_RED, gli::gl::SWIZZLE_GREEN, gli::gl::SWIZZLE_BLUE, gli::gl::SWIZZLE_ONE) ? 0 : 1;

			gli::format FormatD2 = GL.find(FormatD.Internal, FormatD.External, FormatD.Type);
			Error += FormatD2 == TextureD.format() ? 0 : 1;
		}

		return Error;
	}
}//namespace gl32

namespace gl33
{
	int run()
	{
		int Error = 0;

		gli::gl GL(gli::gl::PROFILE_GL33);

		{
			gli::texture2d TextureA(gli::FORMAT_RGB8_UNORM_PACK8, gli::texture2d::extent_type(2), 1, gli::texture2d::swizzles_type(gli::SWIZZLE_RED, gli::SWIZZLE_GREEN, gli::SWIZZLE_BLUE, gli::SWIZZLE_ALPHA));
			gli::gl::format FormatA = GL.translate(TextureA.format(), TextureA.swizzles());

			Error += FormatA.Internal == gli::gl::INTERNAL_RGB8_UNORM ? 0 : 1;
			Error += FormatA.External == gli::gl::EXTERNAL_RGB ? 0 : 1;
			Error += FormatA.Type == gli::gl::TYPE_U8 ? 0 : 1;
			Error += FormatA.Swizzles == gli::gl::swizzles(gli::gl::SWIZZLE_RED, gli::gl::SWIZZLE_GREEN, gli::gl::SWIZZLE_BLUE, gli::gl::SWIZZLE_ONE) ? 0 : 1;
		}

		{
			gli::texture2d TextureB(gli::FORMAT_BGR8_UNORM_PACK8, gli::texture2d::extent_type(2), 1, gli::texture2d::swizzles_type(gli::SWIZZLE_RED, gli::SWIZZLE_GREEN, gli::SWIZZLE_BLUE, gli::SWIZZLE_ALPHA));
			gli::gl::format FormatB = GL.translate(TextureB.format(), TextureB.swizzles());

			Error += FormatB.Internal == gli::gl::INTERNAL_RGB8_UNORM ? 0 : 1;
			Error += FormatB.External == gli::gl::EXTERNAL_RGB ? 0 : 1;
			Error += FormatB.Type == gli::gl::TYPE_U8 ? 0 : 1;
			Error += FormatB.Swizzles == gli::gl::swizzles(gli::gl::SWIZZLE_BLUE, gli::gl::SWIZZLE_GREEN, gli::gl::SWIZZLE_RED, gli::gl::SWIZZLE_ONE) ? 0 : 1;
		}

		{
			gli::texture2d TextureC(gli::FORMAT_R5G6B5_UNORM_PACK16, gli::texture2d::extent_type(2), 1, gli::texture2d::swizzles_type(gli::SWIZZLE_RED, gli::SWIZZLE_GREEN, gli::SWIZZLE_BLUE, gli::SWIZZLE_ALPHA));
			gli::gl::format FormatC = GL.translate(TextureC.format(), TextureC.swizzles());

			Error += FormatC.Internal == gli::gl::INTERNAL_R5G6B5 ? 0 : 1;
			Error += FormatC.External == gli::gl::EXTERNAL_RGB ? 0 : 1;
			Error += FormatC.Type == gli::gl::TYPE_UINT16_R5G6B5_REV ? 0 : 1;
			Error += FormatC.Swizzles == gli::gl::swizzles(gli::gl::SWIZZLE_RED, gli::gl::SWIZZLE_GREEN, gli::gl::SWIZZLE_BLUE, gli::gl::SWIZZLE_ONE) ? 0 : 1;

			gli::format FormatD2 = GL.find(FormatC.Internal, FormatC.External, FormatC.Type);
			Error += FormatD2 == TextureC.format() ? 0 : 1;
		}

		{
			gli::texture2d TextureD(gli::FORMAT_B5G6R5_UNORM_PACK16, gli::texture2d::extent_type(2), 1, gli::texture2d::swizzles_type(gli::SWIZZLE_RED, gli::SWIZZLE_GREEN, gli::SWIZZLE_BLUE, gli::SWIZZLE_ALPHA));
			gli::gl::format FormatD = GL.translate(TextureD.format(), TextureD.swizzles());

			Error += FormatD.Internal == gli::gl::INTERNAL_R5G6B5 ? 0 : 1;
			Error += FormatD.External == gli::gl::EXTERNAL_RGB ? 0 : 1;
			Error += FormatD.Type == gli::gl::TYPE_UINT16_R5G6B5 ? 0 : 1;
			Error += FormatD.Swizzles == gli::gl::swizzles(gli::gl::SWIZZLE_RED, gli::gl::SWIZZLE_GREEN, gli::gl::SWIZZLE_BLUE, gli::gl::SWIZZLE_ONE) ? 0 : 1;

			gli::format FormatD2 = GL.find(FormatD.Internal, FormatD.External, FormatD.Type);
			Error += FormatD2 == TextureD.format() ? 0 : 1;
		}

		return Error;
	}
}//namespace gl33

namespace es20
{
	int run()
	{
		int Error = 0;

		gli::gl GL(gli::gl::PROFILE_ES20);

		{
			gli::texture2d TextureA(gli::FORMAT_RGBA16_SFLOAT_PACK16, gli::texture2d::extent_type(2), 1, gli::texture2d::swizzles_type(gli::SWIZZLE_RED, gli::SWIZZLE_GREEN, gli::SWIZZLE_BLUE, gli::SWIZZLE_ALPHA));
			gli::gl::format FormatA = GL.translate(TextureA.format(), TextureA.swizzles());

			// With OpenGL ES 2, the internal format is the external format so Internal is pretty much moot but this is the responsability of GLI user.
			Error += FormatA.Internal == gli::gl::INTERNAL_RGBA16F ? 0 : 1;
			Error += FormatA.External == gli::gl::EXTERNAL_RGBA ? 0 : 1;
			Error += FormatA.Type == gli::gl::TYPE_F16_OES ? 0 : 1;
			Error += FormatA.Swizzles == gli::gl::swizzles(gli::gl::SWIZZLE_RED, gli::gl::SWIZZLE_GREEN, gli::gl::SWIZZLE_BLUE, gli::gl::SWIZZLE_ALPHA) ? 0 : 1;
		}

		{
			gli::texture2d TextureB(gli::FORMAT_BGRA8_UNORM_PACK8, gli::texture2d::extent_type(2), 1, gli::texture2d::swizzles_type(gli::SWIZZLE_RED, gli::SWIZZLE_GREEN, gli::SWIZZLE_BLUE, gli::SWIZZLE_ALPHA));
			gli::gl::format FormatB = GL.translate(TextureB.format(), TextureB.swizzles());

			Error += FormatB.Internal == gli::gl::INTERNAL_BGRA8_UNORM ? 0 : 1;
			Error += FormatB.External == gli::gl::EXTERNAL_BGRA ? 0 : 1;
			Error += FormatB.Type == gli::gl::TYPE_U8 ? 0 : 1;
			Error += FormatB.Swizzles == gli::gl::swizzles(gli::gl::SWIZZLE_RED, gli::gl::SWIZZLE_GREEN, gli::gl::SWIZZLE_BLUE, gli::gl::SWIZZLE_ALPHA) ? 0 : 1;
		}

		return Error;
	}
}//namespace es20

namespace es30
{
	int run()
	{
		int Error = 0;

		gli::gl GL(gli::gl::PROFILE_ES30);

		{
			gli::texture2d TextureA(gli::FORMAT_RGBA16_SFLOAT_PACK16, gli::texture2d::extent_type(2), 1, gli::texture2d::swizzles_type(gli::SWIZZLE_RED, gli::SWIZZLE_GREEN, gli::SWIZZLE_BLUE, gli::SWIZZLE_ALPHA));
			gli::gl::format FormatA = GL.translate(TextureA.format(), TextureA.swizzles());

			Error += FormatA.Internal == gli::gl::INTERNAL_RGBA16F ? 0 : 1;
			Error += FormatA.External == gli::gl::EXTERNAL_RGBA ? 0 : 1;
			Error += FormatA.Type == gli::gl::TYPE_F16 ? 0 : 1;
			Error += FormatA.Swizzles == gli::gl::swizzles(gli::gl::SWIZZLE_RED, gli::gl::SWIZZLE_GREEN, gli::gl::SWIZZLE_BLUE, gli::gl::SWIZZLE_ALPHA) ? 0 : 1;
		}

		{
			gli::texture2d TextureA(gli::FORMAT_RGB8_UNORM_PACK8, gli::texture2d::extent_type(2), 1, gli::texture2d::swizzles_type(gli::SWIZZLE_RED, gli::SWIZZLE_GREEN, gli::SWIZZLE_BLUE, gli::SWIZZLE_ALPHA));
			gli::gl::format FormatA = GL.translate(TextureA.format(), TextureA.swizzles());

			Error += FormatA.Internal == gli::gl::INTERNAL_RGB8_UNORM ? 0 : 1;
			Error += FormatA.External == gli::gl::EXTERNAL_RGB ? 0 : 1;
			Error += FormatA.Type == gli::gl::TYPE_U8 ? 0 : 1;
			Error += FormatA.Swizzles == gli::gl::swizzles(gli::gl::SWIZZLE_RED, gli::gl::SWIZZLE_GREEN, gli::gl::SWIZZLE_BLUE, gli::gl::SWIZZLE_ONE) ? 0 : 1;
		}

		{
			gli::texture2d TextureB(gli::FORMAT_BGR8_UNORM_PACK8, gli::texture2d::extent_type(2), 1, gli::texture2d::swizzles_type(gli::SWIZZLE_RED, gli::SWIZZLE_GREEN, gli::SWIZZLE_BLUE, gli::SWIZZLE_ALPHA));
			gli::gl::format FormatB = GL.translate(TextureB.format(), TextureB.swizzles());

			Error += FormatB.Internal == gli::gl::INTERNAL_RGB8_UNORM ? 0 : 1;
			Error += FormatB.External == gli::gl::EXTERNAL_RGB ? 0 : 1;
			Error += FormatB.Type == gli::gl::TYPE_U8 ? 0 : 1;
			Error += FormatB.Swizzles == gli::gl::swizzles(gli::gl::SWIZZLE_BLUE, gli::gl::SWIZZLE_GREEN, gli::gl::SWIZZLE_RED, gli::gl::SWIZZLE_ONE) ? 0 : 1;
		}

		{
			gli::texture2d TextureB(gli::FORMAT_BGRA8_UNORM_PACK8, gli::texture2d::extent_type(2), 1, gli::texture2d::swizzles_type(gli::SWIZZLE_RED, gli::SWIZZLE_GREEN, gli::SWIZZLE_BLUE, gli::SWIZZLE_ALPHA));
			gli::gl::format FormatB = GL.translate(TextureB.format(), TextureB.swizzles());

			Error += FormatB.Internal == gli::gl::INTERNAL_RGBA8_UNORM ? 0 : 1;
			Error += FormatB.External == gli::gl::EXTERNAL_RGBA ? 0 : 1;
			Error += FormatB.Type == gli::gl::TYPE_U8 ? 0 : 1;
			Error += FormatB.Swizzles == gli::gl::swizzles(gli::gl::SWIZZLE_BLUE, gli::gl::SWIZZLE_GREEN, gli::gl::SWIZZLE_RED, gli::gl::SWIZZLE_ALPHA) ? 0 : 1;
		}

		{
			gli::texture2d TextureB(gli::FORMAT_BGRA8_UNORM_PACK8, gli::texture2d::extent_type(2), 1, gli::texture2d::swizzles_type(gli::SWIZZLE_BLUE, gli::SWIZZLE_GREEN, gli::SWIZZLE_RED, gli::SWIZZLE_ALPHA));
			gli::gl::format FormatB = GL.translate(TextureB.format(), TextureB.swizzles());

			Error += FormatB.Internal == gli::gl::INTERNAL_RGBA8_UNORM ? 0 : 1;
			Error += FormatB.External == gli::gl::EXTERNAL_RGBA ? 0 : 1;
			Error += FormatB.Type == gli::gl::TYPE_U8 ? 0 : 1;
			Error += FormatB.Swizzles == gli::gl::swizzles(gli::gl::SWIZZLE_RED, gli::gl::SWIZZLE_GREEN, gli::gl::SWIZZLE_BLUE, gli::gl::SWIZZLE_ALPHA) ? 0 : 1;
		}

		return Error;
	}
}//namespace es30

int main()
{
	int Error(0);

	Error += ktx::run();
	Error += gl32::run();
	Error += gl33::run();
	Error += es20::run();
	Error += es30::run();

	return Error;
}
