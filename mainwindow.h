#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
// Point Cloud Library
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/visualization/pcl_visualizer.h>

// Visualization Toolkit (VTK)
#include <vtkRenderWindow.h>
#include<QVTKWidget.h>

#include<QOpenGLWidget>
#include<QVTKOpenGLNativeWidget.h>
#include<QOpenGLFunctions>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLBuffer>
#include<osg/Geometry>//ADD
#include <vtkPointPicker.h>
//#include <vtkGenericOpenGLRenderWindow.h>
#include "vtkRenderWindow.h"
typedef pcl::PointXYZRGBA PointT;
typedef pcl::PointCloud<PointT> PointCloudT;
//namespace Ui
//{
//  class main_window;
//}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
private:
     QVTKWidget *qvtkwindow;
//    QVTKOpenGLNativeWidget *qvtkopenglwindow;
//    vtkSmartPointer<vtkGenericOpenGLRenderWindow> _renderWindow;
protected:
    boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer;
    PointCloudT::Ptr cloud;
    void showpcl(std::string spath);
private slots:
//    void showpcl();
    void on_pushButton_clicked();
};
 #endif // MAINWINDOW_H
