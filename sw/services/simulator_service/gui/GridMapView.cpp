#include "GridMapView.h"
#include <QPainter>
#include <QColor>

GridMapView::GridMapView(QWidget* parent)
    : QWidget(parent) {}

/*void GridMapView::set_grid(const grid_map* g) {
    grid = g;
    update(); // Trigger repaint
}

void GridMapView::set_path(const std::vector<grid_cell>& new_path) {
    path = new_path;
    update();
}*/

void GridMapView::paintEvent(QPaintEvent*) {
    /*if (!grid) return;

    QPainter painter(this);

    int w = grid->get_width();
    int h = grid->get_height();

    resize(w * cell_size + cell_size, h * cell_size + cell_size );

    for (int y = 0; y < h; ++y) {
        for (int x = 0; x < w; ++x) {
            QRect rect(x * cell_size, y * cell_size, cell_size, cell_size);

            if (!grid->is_free(x, y)) {
                painter.fillRect(rect, Qt::red);
            } else if( grid->is_strictly_free( x, y ) )
            {
                painter.fillRect(rect, Qt::white);
            }
            else
            {
                painter.fillRect(rect, Qt::green );
            }

            painter.setPen(Qt::gray);
            painter.drawRect(rect);
        }
    }

    // Draw path
    painter.setPen(QPen(Qt::black, 2));
    for (size_t i = 1; i < path.size(); ++i) {
        int x1 = path[i - 1].x * cell_size + cell_size / 2;
        int y1 = path[i - 1].y * cell_size + cell_size / 2;
        int x2 = path[i].x * cell_size + cell_size / 2;
        int y2 = path[i].y * cell_size + cell_size / 2;
        painter.drawLine(x1, y1, x2, y2);
    }*/
}
