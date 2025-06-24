#include "SimView.h"

#include <QPainter>
#include <QBrush>
#include <QThread>
//#include "sim/path_planner.h"

bool show_border = true;
bool show_obs = true;
bool show_path_as_dots = false;
bool show_path_as_lines = false;
bool show_robot = true;

static size_t inc( 0 );

SimView::SimView(const i_map* map_ptr, const i_robot* robot_ptr, QWidget *parent)
    : m_map_ptr( map_ptr )
    , m_robot_ptr( robot_ptr )
    , QWidget( parent )
{
    this->resize( 600, 600 );
}

void SimView::paintEvent( QPaintEvent *event )
{
    Q_UNUSED( event );

    QPainter qp( this );

    QBrush std_brush( qp.brush() );
    QPen std_pen( qp.pen() );

    if( show_border )
    {
        qp.setPen( Qt::red );

        QPolygon border;

        for( const point_2d& point : m_map_ptr->get_boundary().vertices() )
        {
            border << QPoint( point.x, point.y );
        }

        qp.drawPolygon( border );

    }

    if( show_obs )
    {
        qp.setPen( Qt::green );
        qp.setBrush( Qt::green );

        for( const polygon& obstacle : m_map_ptr->get_soft_obstacles() )
        {
            QPolygon obs;

            for( const point_2d& point : obstacle.vertices() )
            {
                obs << QPoint( point.x, point.y );
            }

            qp.drawPolygon( obs );
        }

        qp.setPen( Qt::red );
        qp.setBrush( Qt::red );

        for( const polygon& obstacle : m_map_ptr->get_obstacles() )
        {
            QPolygon obs;

            for( const point_2d& point : obstacle.vertices() )
            {
                obs << QPoint( point.x, point.y );
            }

            qp.drawPolygon( obs );
        }

        qp.setPen( std_pen );
        qp.setBrush( std_brush );
    }
/*
    if( show_path_as_dots )
    {
        qp.setPen( QPen( Qt::blue, 2 ) );

        std::vector<point_2d> path_points( generateSweepPathWithObstacles( map_ptr, 5 ) );

        for( auto it = path_points.begin(); it != path_points.end(); ++it )
        {
            qp.drawPoint( it->x, it-> y );
        }
    }

    if( show_path_as_lines )
    {
        qp.setPen( QPen( Qt::blue, 2 ) );

        std::vector<LineSegment> segs( toSegments( makeSimpleFilteredPath( generateSweepPathWithObstacles( map_ptr, 5 ), map_ptr )));

        for( const auto& seg : segs )
        {
            qp.drawLine( seg.start.x, seg.start.y, seg.end.x, seg.end.y );
        }
    }*/
    if( show_robot )
    {
        qp.setPen( QPen( Qt::black, 2 ) );

        qp.drawEllipse( m_robot_ptr->get_position().x,
                        m_robot_ptr->get_position().y,
                        10,
                        10 );

        qp.setPen( std_pen );
        qp.setBrush( std_brush );
    }
}
