#include "mainwindow.h"
#include"iostream"
#include<QMenuBar>
#include<QMenu>
#include<QAction>
#include<QDebug>
#include<QToolBar>
#include<QPushButton>
#include<QStatusBar>
#include<QLabel>
#include<QTextEdit>
#include<QDockWidget>
#include<QMessageBox>
#include<QDialog>
#include<QFile>
#include<QFileDialog>

#include <QToolButton>

#include<iostream>
#include<pcl/io/pcd_io.h>
#include<pcl/point_types.h>
#include <pcl/visualization/cloud_viewer.h>
//#include "../build-HDMAP-Desktop_Qt_5_9_5_GCC_64bit-Debug/ui_mainwindow.h"
#include <vtkAutoInit.h>
//#include <vtkoutputwindow.h>
//VTK_MODULE_INIT(vtkRenderingOpenGL);
//VTK_MODULE_INIT(vtkInteractionStyle);

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
//      ui (new Ui::main_window)
{
//    m_vao = new QOpenGLVertexArrayObject();
//    m_vao->create();
//     m_vao->bind();
//    ui->setupUi(this);
    QMenuBar *mBar= menuBar();//建立菜单
    /*添加菜单项*/
    QMenu *pFile = mBar->addMenu("文件");
    QMenu *pedit = mBar->addMenu("编辑");
    QMenu *ptool = mBar->addMenu("工具");
//    QMenu *pvisual= mBar->addMenu("视图");
    QMenu *phelp = mBar->addMenu("帮助");


    /*添加动作*/
    QAction *pNew = pFile->addAction("新建");
    QAction *pOpen=pFile->addAction("打开");
    QAction *psave =pFile->addAction("保存");

    QAction *pphelp =phelp->addAction("help");

    QAction *pdelet=pedit->addAction("删除图元");
    QAction *pcut=pedit->addAction("剪裁图元");

    QAction *tpaint =ptool->addAction("绘图");

    ptool->setFocusPolicy(Qt::StrongFocus);
//    ptool->setIcon(QIcon ("Resources/Icons/RoadType.png"));
    ptool->setToolTip("Road type");
//    ptool->setIcon(QIcon (":/Resources/Resources/Icons/Road.png"));
    /*设置分隔线*/
     pFile->addSeparator();
     ptool->addSeparator();

    /*匿名函数的信号与槽*/


     //help
    connect(pphelp,&QAction::triggered,
            [=]()
            {
        //跳转到URL


            }
            );
    //新建文件
     connect(pNew,&QAction::triggered,
             [=]()
            {
               //被按下的处理程序
         //


         //
         int ret= QMessageBox::question(this,"新建文件","是否新建文件",QMessageBox::Yes,QMessageBox::No,QMessageBox::Cancel);
         switch (ret) {
         case QMessageBox::Yes:
             qDebug() <<"确认新建";
             //被按下后的处理

             break;
         case QMessageBox::No:
             qDebug() <<"取消新建";
             //被按下后的处理

             break;
         default:
             break;
         }

//               qDebug() <<"新建被按下";
             }
            );

     /*打开文件*/
     connect(pOpen,&QAction::triggered,
             [=]()
             {
                QString qpath= QFileDialog::getOpenFileName(this,"open","/home",
                                                           "pointclou(*.pcd *.ply);;souce(*.cpp *.h);;Text(*.text *.xml);;images(*.png *jpg)"
                                                           ,0,QFileDialog::DontUseNativeDialog);//设置对话框格式
                qDebug() << qpath;
//                QFile plcfile(qpath);
//                if (!plcfile.open(QIODevice::ReadOnly|QIODevice::Text))
//                    return;
                std::string spath = qpath.toStdString();//文件名格式装换从Qstring到std::string
                showpcl(spath);
             }
             );
     /*保存文件*/
     connect(psave,&QAction::triggered,
             [=]()
             {
               int ret= QMessageBox::question(this,"保存文件","是否保存文件",
                                              QMessageBox::Yes,QMessageBox::No,QMessageBox::Cancel);//返回枚举整形类
               switch (ret)
               {
               case QMessageBox::Yes:
                   qDebug() <<"确认保存";
                   //被按下后的处理


                   //sql数据库文件导出

                   break;
               case QMessageBox::No:
                   qDebug() <<"取消保存";
                   //被按下后的处理

                   break;
               default:
                   break;
               }
             }
             );
     //工具栏快捷键添加
     QToolBar *toolBar=addToolBar("toolBar");
     toolBar->addAction(pNew);

     QPushButton *b= new QPushButton(this);
     b->setText("^_^");
     toolBar->addWidget(b);
     connect(b,&QPushButton::clicked,
             [=]()
     {
         b->setText("123");
     }

             );

    //添加状态栏
     QStatusBar *sBar =statusBar();
     QLabel *label=new QLabel(this);
     label->setText("Normal text file ");
     sBar->addWidget(label);
     //状态栏从左往右添加
     sBar->addWidget(new QLabel("2",this));

     //文本编辑区
//     QTextEdit *textedit=new QTextEdit(this);
//     setCentralWidget(textedit);
//     resize(400,300);

     //浮动窗口
//     QDockWidget *dockwidget=new QDockWidget(this);
//     addDockWidget(Qt::RightDockWidgetArea ,dockwidget);
//     QTextEdit *textedit1=new QTextEdit(this);
//     dockwidget->setWidget(textedit1);

/* Set up the QVTK window*/
//可视化窗口
      qvtkwindow = new QVTKWidget(this);
      setCentralWidget(qvtkwindow);
      resize(1000,800);
      viewer.reset (new pcl::visualization::PCLVisualizer ("viewer", false));
      viewer->setBackgroundColor(0,0,0);
       qvtkwindow->SetRenderWindow(viewer->getRenderWindow ());
       viewer->setupInteractor (qvtkwindow->GetInteractor(), qvtkwindow->GetRenderWindow ());
       qvtkwindow->update();
//     qvtkopenglwindow = new QVTKOpenGLNativeWidget(this);
//     setCentralWidget(qvtkopenglwindow);
//     resize(1000,800);
//     //
//     auto renderer = vtkSmartPointer<vtkRenderer>::New();
//     _renderWindow = vtkSmartPointer<vtkGenericOpenGLRenderWindow>::New();
//     viewer.reset (new pcl::visualization::PCLVisualizer (renderer,_renderWindow,"viewer", false));
// //     viewer.reset (new pcl::visualization::PCLVisualizer ("viewer", false));
// //     viewer->setBackgroundColor(255,255,255);
//     viewer->setBackgroundColor(0,0,0);
//     qvtkopenglwindow->SetRenderWindow(viewer->getRenderWindow ());
//     viewer->setupInteractor (qvtkopenglwindow->GetInteractor(), qvtkopenglwindow->GetRenderWindow ());
//     qvtkopenglwindow->update ();

}

/*pointcloud visualize*/
void MainWindow::showpcl(std::string spath)
{
    pcl::PointCloud<pcl::PointXYZI>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZI>);
        if (-1 == pcl::io::loadPCDFile(spath,*cloud))
        {
            cout << "error input!" << endl;
        }
//                    QMessageBox::information(NULL, "Title", "read completed");
        cout << "打开成功"<<cloud->points.size() << endl;
        viewer->setBackgroundColor(0,0,0);
        //按照点云强度信息进行显示
        pcl::visualization::PointCloudColorHandlerGenericField<pcl::PointXYZI> fildColor(cloud, "intensity");
//        viewer->addPointCloud<pcl::PointXYZRGB> (cloud, rgb, "sample cloud");//按照颜色信息显示
        viewer->addPointCloud<pcl::PointXYZI> (cloud,fildColor, "sample cloud");
        viewer->resetCamera();
//        viewer->setCameraPosition(0, -15, -15,
//                                        0,  0,  5,
//                                        0, -1,  0);
        viewer->addCoordinateSystem(1,0,0,0);
        viewer->initCameraParameters ();
//        viewer->addLine<pcl::PointXYZRGB> (cloud->points[0],
//                                             cloud->points[cloud->size() - 1], "line");
//        qvtkopenglwindow->update();
        qvtkwindow->update();
        while (!viewer->wasStopped())
        {
        viewer->spinOnce(100);
        }
        cout << "导入成功，点云数为："<<cloud->points.size() << endl;

}

MainWindow::~MainWindow()
{

}

void MainWindow::on_pushButton_clicked()
{

}
