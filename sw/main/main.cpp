#include <iostream>
#include <memory>

#ifdef DESKTOP_RUNTIME
#include <QApplication>
#endif

#include "builder/ash_builder.h"
#include <cstdio>

int main( int argc, char* argv[] )
{
    std::ios::sync_with_stdio( false );

#ifdef DESKTOP_RUNTIME
    QApplication qt_app( argc, argv );
#endif
    
    builder::ash_builder app_builder( argc, argv );
    
    std::unique_ptr<ash::ash> app( app_builder.build() );

    app->start();

#ifdef DESKTOP_RUNTIME
    qt_app.exec();
#else
    std::cout << '\n' << "Press any key to quit..." << std::endl;
    std::cin.get();// != '\n' );
#endif

    app->stop();
}
