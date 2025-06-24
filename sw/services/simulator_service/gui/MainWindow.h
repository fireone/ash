#pragma once

#include "utils/i_map.h"
#include "robot/i_robot.h"

#include <QtWidgets/QMainWindow>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow( const i_map* map_ptr, const i_robot* robot_ptr, QWidget* parent = nullptr );
    ~MainWindow();

private:
    const i_map* m_map_ptr;
    const i_robot* m_robot_ptr;

    //SimView*     m_pMapView;
    //GridMapView* m_pGridMapView;

    void update_view();
};
