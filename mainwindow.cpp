#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    static bool faster_checked = true;
    static bool slower_checked = false;

    FacileMenu* menu = (new FacileMenu(this))
        ->setTipArea("Ctrl+P")
        ->setSplitInRow(true);

    menu->addAction(QIcon(":/icons/run"), "开始播放 (&S)", [=]{
        qDebug() << "=>开始播放";
    })->tip("Ctrl+S");

    menu->addAction(QIcon(":/icons/pause"), "暂停 (&P)", [=]{
        qDebug() << "=>暂停";
    })->tip("Ctrl+P");

    menu->addAction(QIcon(":/icons/resume"), "继续 (&R)", [=]{
        qDebug() << "=>继续";
    })->disable()->tip("Ctrl+R");

    menu->addAction(QIcon(":/icons/stop"), "停止 (&T)", [=]{
        qDebug() << "=>停止";
    })->tip("Ctrl+T");
    menu->addSeparator();

    menu->addLinger(QIcon(":/icons/faster"), "加速", [=]{
        qDebug() << "=>加速";
        faster_checked = !faster_checked;
    })->setChecked(faster_checked);

    menu->addLinger(QIcon(":/icons/slower"), "减速", [=]{
        qDebug() << "=>减速";
        slower_checked = !slower_checked;
    })->setChecked(slower_checked);

    menu->addRow([=]{
        menu->addAction("按钮1");
        menu->addAction("按钮2");
        menu->addAction("按钮3");
    });

    auto subMenu = menu->addMenu("子菜单0");
    {
        subMenu->addAction(QIcon(":/icons/run"), "开始播放", [=]{
            qDebug() << "=>开始播放";
        });

        subMenu->addAction(QIcon(":/icons/pause"), "暂停", [=]{
            qDebug() << "=>暂停";
        });

        subMenu->addAction(QIcon(":/icons/resume"), "继续", [=]{
            qDebug() << "=>继续";
        })->disable();

        subMenu->addAction(QIcon(":/icons/stop"), "停止", [=]{
            qDebug() << "=>停止";
        });

        subMenu->addAction(QIcon(":/icons/faster"), "加速", [=]{
            qDebug() << "=>加速";
            faster_checked = !faster_checked;
        })->setChecked(faster_checked);

        auto subMenu2 = subMenu->addMenu("子菜单");
        {
            subMenu2->addAction(QIcon(":/icons/run"), "开始播放", [=]{
                qDebug() << "=>开始播放";
            });

            subMenu2->addAction(QIcon(":/icons/pause"), "暂停", [=]{
                qDebug() << "=>暂停";
            });

            subMenu2->addAction(QIcon(":/icons/resume"), "继续", [=]{
                qDebug() << "=>继续";
            })->disable();

            subMenu2->addAction(QIcon(":/icons/stop"), "停止", [=]{
                qDebug() << "=>停止";
            });

            subMenu2->addAction(QIcon(":/icons/faster"), "加速", [=]{
                qDebug() << "=>加速";
                faster_checked = !faster_checked;
            })->setChecked(faster_checked);

            auto subMenu3 = subMenu2->addMenu("子菜单");
            subMenu3->addAction("没有子菜单了");
        }
    }

    auto subMenu2 = menu->addMenu("子菜单1");
    {
        subMenu2->addAction(QIcon(":/icons/run"), "开始播放", [=]{
            qDebug() << "=>开始播放";
        });

        subMenu2->addAction(QIcon(":/icons/pause"), "暂停", [=]{
            qDebug() << "=>暂停";
        });
    }

    auto subMenu3 = menu->addMenu("子菜单2");
    {

        subMenu3->addLinger(QIcon(":/icons/resume"), "继续", [=]{
            qDebug() << "=>继续";
        })->disable();

        subMenu3->addLinger(QIcon(":/icons/stop"), "停止", [=]{
            qDebug() << "=>停止";
        });
    }

    auto subMenu4 = menu->addMenu("子菜单3");
    {
        subMenu4->addAction(QIcon(":/icons/faster"), "加速", [=]{
            qDebug() << "=>加速";
            faster_checked = !faster_checked;
        })->setChecked(faster_checked);
    }


    menu->exec(QCursor::pos());
}

void MainWindow::on_pushButton_2_clicked()
{
    static bool faster_checked = true;
    static bool slower_checked = false;

    FacileMenu* menu = new FacileMenu(this);
    menu->setTipArea("Ctrl+P");

    menu->addRow([=]{
        menu->addAction("按钮1")->disable();
        menu->addAction("按钮2")->disable();
        menu->addAction("按钮3");
    });

    menu->addAction(QIcon(":/icons/run"), "开始播放 (&S)", [=]{
        qDebug() << "=>开始播放";
    })->tip("Ctrl+S");

    menu->addAction(QIcon(":/icons/pause"), "暂停 (&P)", [=]{
        qDebug() << "=>暂停";
    })->tip("Ctrl+P");

    menu->addAction(QIcon(":/icons/resume"), "继续 (&R)", [=]{
        qDebug() << "=>继续";
    })->disable()->tip("Ctrl+R");

    menu->addAction(QIcon(":/icons/stop"), "停止 (&T)", [=]{
        qDebug() << "=>停止";
    })->tip("Ctrl+T");
    menu->addSeparator();

    menu->addAction(QIcon(), "静态回调方法", staticFunction);
//    menu->fun2(1, "类内回调方法", this, &MainWindow::classFunction);

    menu->addAction(QIcon(":/icons/faster"), "加速", [=]{
        qDebug() << "=>加速";
        faster_checked = !faster_checked;
    })->setChecked(faster_checked);

    menu->addAction(QIcon(":/icons/slower"), "减速", [=]{
        qDebug() << "=>减速";
        slower_checked = !slower_checked;
    })->setChecked(slower_checked);

    menu->beginRow();
    menu->addAction(QIcon(":/icons/run"));
    menu->addAction(QIcon(":/icons/pause"));
    menu->split()->addAction(QIcon(":/icons/resume"));
    menu->addAction(QIcon(":/icons/stop"))->disable();
    menu->endRow();

    menu->addAction(QIcon(":/icons/faster"), "加速", [=]{
        qDebug() << "=>加速";
        faster_checked = !faster_checked;
    })->setChecked(faster_checked)->disable();

    menu->addAction(QIcon(":/icons/slower"), "减速", [=]{
        qDebug() << "=>减速";
        slower_checked = !slower_checked;
    })->setChecked(slower_checked)->disable();

    menu->beginRow();
    menu->addAction("按钮1");
    menu->addAction("按钮2")->disable();
    menu->addAction("按钮3")->disable();
    menu->endRow();


    menu->exec(QCursor::pos());
}

void MainWindow::staticFunction()
{
    qDebug() << "静态方法回调";
}

void MainWindow::classFunction()
{
    qDebug() << "类内方法回调";
}
