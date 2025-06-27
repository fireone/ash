#pragma once

#include "EventBridge.h"

#include "utils/i_map.h"

#include "robot/i_robot.h"

#include <QtWidgets/QMainWindow>

#include <memory>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow( const i_map* map_ptr, const i_robot* robot_ptr, services::event_service::i_event_service* event_service_ptr, QWidget* parent = nullptr );
    ~MainWindow();

private:
    const i_map* m_map_ptr;
    const i_robot* m_robot_ptr;

    std::unique_ptr<EventBridge> m_event_bridge_ptr;

    //SimView*     m_pMapView;
    //GridMapView* m_pGridMapView;

    void update_view();
};
