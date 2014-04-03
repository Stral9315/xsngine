#include "XSSystem/XSInclude.h"

#include <Windows.h> // curse you, monolithic headers!
#include <sys/stat.h>

namespace XS {

	namespace OS {

		void GetCurrentWorkingDirectory( char *cwd, size_t bufferLen ) {
			_getcwd( cwd, (int)bufferLen - 1 );
			cwd[FILENAME_MAX - 1] = '\0';
		}

		bool MkDir( const char *path ) {
			if ( !CreateDirectory( path, NULL ) ) {
				if ( GetLastError() != ERROR_ALREADY_EXISTS )
					return false;
			}

			return true;
		}

		bool Stat( const char *path ) {
			struct _stat buf;

			if ( _stat( path, &buf ) )
				return false;

			return true;
		}

	} // namespace OS

} // namespace XS
