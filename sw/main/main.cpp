#include <iostream>
#include <memory>

#include "builder/ash_builder.h"
#include <cstdio>

int main( int argc, char* argv[] )
{
    std::ios::sync_with_stdio( false );
    
    builder::ash_builder app_builder( argc, argv );
    
    std::unique_ptr<ash::ash> app( app_builder.build() );

    app->start();

    do
    {
        std::cout << '\n' << "Press enter key to quit..." << std::endl;
    }
    while( std::cin.get() != '\n' );

    app->stop();

}
