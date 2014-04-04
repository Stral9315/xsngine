#pragma once

namespace XS {

	namespace Client {

		void	Init		( void );
		void	Shutdown	( void );
		void	NetworkPump	( void );
		void	RunFrame	( double dt );
		void	DrawFrame	( void );

	} // namespace Client

} // namespace XS
