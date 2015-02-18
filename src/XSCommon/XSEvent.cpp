#include <queue>

#include "XSCommon/XSCommon.h"
#include "XSCommon/XSEvent.h"
#include "XSCommon/XSCvar.h"
#include "XSCommon/XSString.h"
#include "XSCommon/XSConsole.h"
#include "XSCommon/XSError.h"
#include "XSInput/XSKeys.h"

namespace XS {

	namespace Event {

		static Cvar *debug_events = nullptr;

		// this is cleared each pump. we may just want to expand
		//	as necessary and set the head to 0 at the end of each pump
		//	to avoid the overhead of clear()
		static std::queue<XSEvent> events;

		// for debugging
		static const char *eventNames[] = {
			"EventType::Keyboard",
			"EventType::MouseButton",
			"EventType::MouseWheel",
			"EventType::MouseMotion"
		};

		void Init( void ) {
			debug_events = Cvar::Create( "debug_events", "0", "Print debug messages for input events", CVAR_INIT );
		}

		void Queue( const XSEvent *ev ) {
			if ( debug_events->GetBool() ) {
				console.Print( PrintLevel::Normal, "%s %s (%i)\n", XS_FUNCTION, eventNames[(int)ev->type], ev->type );
			}

			events.push( *ev );
		}

		void Pump( void ) {
			while ( !events.empty() ) {
				const XSEvent &ev = events.front();
				switch( ev.type ) {
				case EventType::Keyboard: {
					Client::KeyboardEvent( ev.keyboard );
				} break;

				case EventType::MouseButton: {
					// ...
				} break;

				case EventType::MouseWheel: {
					// ...
				} break;

				case EventType::MouseMotion: {
					// ...
				} break;

				default: {
					throw( XSError( String::Format( "%s Unknown event %i", XS_FUNCTION, ev.type ).c_str() ) );
				} break;
				}
				events.pop();
			}
		}

	} // namespace Event

} // namespace XS
