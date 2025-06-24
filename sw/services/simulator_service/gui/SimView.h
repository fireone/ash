#pragma once

#include "utils/i_map.h"
#include "robot/i_robot.h"

#include <QWidget>

class SimView : public QWidget
{
    Q_OBJECT
public:
    explicit SimView(const i_map* map_ptr, const i_robot* robot_ptr, QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;

private:
    const i_map* m_map_ptr;
    const i_robot* m_robot_ptr;

signals:
};

