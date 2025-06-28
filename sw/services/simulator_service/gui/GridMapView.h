#pragma once

#include <QWidget>
//#include "route/grid_map.h"
#include "utils/grid/grid_cell.h"

class GridMapView : public QWidget {
    Q_OBJECT

public:
    GridMapView(QWidget* parent = nullptr);

public slots:
    //void set_grid(const grid_map* grid);
    void set_path(const std::vector<grid_cell>& path);

protected:
    void paintEvent(QPaintEvent* event) override;

private:
    //const grid_map* grid = nullptr;
    //std::vector<grid_cell> path;

    int cell_size = 10; // pixels per grid cell
};
