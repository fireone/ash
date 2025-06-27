#include "SimulatorControl.h"
#include <QPushButton>
#include <QHBoxLayout>

SimulatorControl::SimulatorControl( QWidget* parent )
    : QWidget(parent)
{
    QHBoxLayout *layout_ptr = new QHBoxLayout( this );

    QPushButton* place_robot_button_ptr = new QPushButton("Place Robot", this);
    QPushButton* path_button_ptr = new QPushButton("Generate Path", this);
    QPushButton* start_button_ptr = new QPushButton("Start Simulation", this);
    QPushButton* stop_button_ptr = new QPushButton("Stop Simulation", this);
    QPushButton* reset_button_ptr = new QPushButton("Reset Simulation", this);

    layout_ptr->addWidget( place_robot_button_ptr );
    layout_ptr->addWidget( path_button_ptr );
    layout_ptr->addWidget( start_button_ptr );
    layout_ptr->addWidget( stop_button_ptr );
    layout_ptr->addWidget( reset_button_ptr );
}

