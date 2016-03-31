#include "XSCommon/XSCommon.h"
#include "XSCommon/XSConsole.h"
#include "XSCommon/XSByteBuffer.h"
#include "XSServer/XSEntityFXRunner.h"

namespace XS {

	namespace ServerGame {

		EntityFXRunner::EntityFXRunner() {
			type = EntityType::FXRunner;
			count = 10u;
			life = 1000u;
		}

		void EntityFXRunner::Update( real64_t dt ) {
			Entity::Update( dt );
		}

		ByteBuffer::Error EntityFXRunner::Serialise( ByteBuffer *buffer ) const {
			ByteBuffer::Error status;
			status = Entity::Serialise( buffer );
			if ( status != ByteBuffer::Error::Success ) {
				return status;
			}

			status = buffer->Write<uint32_t>( count );
			status = buffer->Write<uint32_t>( life );
			if ( status != ByteBuffer::Error::Success ) {
				return status;
			}

			return ByteBuffer::Error::Success;
		}

	} // namespace ServerGame

} // namespace XS
