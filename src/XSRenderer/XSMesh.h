#pragma once

#include <vector>
#include "XSCommon/XSVector.h"

namespace XS {

	namespace Renderer {

		struct Material;
		class ShaderProgram;
		class Texture;

		namespace Backend {
			class Buffer;
		} // namespace Backend

		struct Mesh {

			std::vector<vector3>	 vertices;
			std::vector<vector3>	 normals;
			std::vector<vector2>	 UVs;
			std::vector<uint16_t>	 indices;
			ShaderProgram			*shader;
			Material				*material;
			Texture					*texture;
			Backend::Buffer			*vertexBuffer;
			Backend::Buffer			*indexBuffer;

			// upload mesh to GPU
			void Upload(
				void
			);

			Mesh()
			: shader( nullptr ), material( nullptr ), texture( nullptr ), vertexBuffer( nullptr ),
				indexBuffer( nullptr )
			{
			}
			~Mesh();

		};

	} // namespace Renderer

} // namespace XS
