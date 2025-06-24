#include "MainWindow.h"
#include "GridMapView.h"
#include "SimView.h"
/*
#include "route/grid_map_builder.h"
#include "route/grid_coverage_planner.h"
#include "route/grid_path_optimizer.h"
*/
#include <QDebug>
#include <QTimer>
#include <QHBoxLayout>

MainWindow::MainWindow( const i_map* map_ptr, const i_robot* robot_ptr, QWidget *parent )
    : m_map_ptr( map_ptr )
    , m_robot_ptr( robot_ptr ) 
    , QMainWindow( parent )
    //, m_sim_ptr( sim_ptr )
    //, m_pMapView( nullptr )
    //, m_pGridMapView( nullptr )
{
    QWidget *central_widget_ptr = new QWidget( this );
    this->setCentralWidget( central_widget_ptr );

    QHBoxLayout *layout_ptr = new QHBoxLayout( central_widget_ptr );

    SimView* pMapView = new SimView( m_map_ptr, m_robot_ptr, central_widget_ptr );
    //GridMapView* pGridMapView = new GridMapView( central_widget_ptr );

    layout_ptr->addWidget( pMapView, 1 );
    //layout_ptr->addWidget( pGridMapView, 2 );


    /*grid_map_builder builder(5.0);

    grid_map* pGrid( builder.build_from( m_sim_ptr->get_environment()->get_map() ) );

    m_pGridMapView->set_grid( pGrid );

    grid_cell start_cell{0, 0};

    grid_coverage_planner c_planner( *pGrid, start_cell );
    std::vector<grid_cell> coverage_path = c_planner.compute_coverage_path();


    grid_path_optimizer optimizer;
    std::vector<grid_cell> optimized_path = optimizer.optimize(coverage_path);

    std::vector<grid_cell> diag_optimized_path(optimizer.remove_zigzags(optimized_path) );

    qDebug() << "Path size: " << coverage_path.size() << "\n";
    qDebug() << "Opt  size: " << optimized_path.size() << "\n";
    qDebug() << "Diag size: " << diag_optimized_path.size() << "\n";

    m_pGridMapView->set_path( diag_optimized_path );

    std::vector<point_2d> world_path( grid_map::convert_path_to_world( optimized_path, *pGrid ) );

    m_sim_ptr->get_robot()->set_path( world_path );

    */
    resize( 1920, 1080 );

    QTimer* update_timer = new QTimer(this);
    connect(update_timer, &QTimer::timeout, this, &MainWindow::update_view);
    update_timer->start(16);
}

MainWindow::~MainWindow()
{

}

void MainWindow::update_view()
{
    update();
}
