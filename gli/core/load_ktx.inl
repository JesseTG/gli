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
/// @file gli/core/load_ktx.inl
/// @date 2013-03-12 / 2013-03-12
/// @author Christophe Riccio
///////////////////////////////////////////////////////////////////////////////////

#include <fstream>
#include <cassert>

namespace gli{
namespace detail
{
	struct ktxHeader
	{
		glm::uint32 Endianness;
		glm::uint32 GLType;
		glm::uint32 GLTypeSize;
		glm::uint32 GLFormat;
		glm::uint32 GLInternalFormat;
		glm::uint32 GLBaseInternalFormat;
		glm::uint32 PixelWidth;
		glm::uint32 PixelHeight;
		glm::uint32 PixelDepth;
		glm::uint32 NumberOfArrayElements;
		glm::uint32 NumberOfFaces;
		glm::uint32 NumberOfMipmapLevels;
		glm::uint32 BytesOfKeyValueData;
	};
}//namespace detail

inline storage loadStorageKTX
(
	std::string const & Filename
)
{
	std::ifstream File(Filename.c_str(), std::ios::in | std::ios::binary);
	assert(!File.fail());

	// Reading the magic number
	char Magic[12];
	File.read((char*)&Magic, sizeof(Magic));
	assert(strncmp(Magic, "«KTX 11»\r\n\x1A\n", sizeof(Magic)) == 0);

	// Reading the header
	detail::ktxHeader Header;
	File.read((char*)&Header, sizeof(Header));

	if(File.fail())
		return storage();

	return storage();
}

}//namespace gli

