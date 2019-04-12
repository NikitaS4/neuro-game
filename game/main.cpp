#include "stdafx.hpp"

#include "game.hpp"


std::tuple<QWidget *, Qt3DExtras::Qt3DWindow *, Qt3DCore::QEntity *>
create3dView()
{
    Qt3DExtras::Qt3DWindow * view = new Qt3DExtras::Qt3DWindow;
    view->defaultFrameGraph()->setClearColor(QColor(QRgb(0x2D9EB5)));

    Qt3DCore::QEntity * rootEntity = new Qt3DCore::QEntity;
    view->setRootEntity(rootEntity);

    QWidget * container = QWidget::createWindowContainer(view);
    container->setMinimumSize(QSize(200, 100));
    container->setMaximumSize(view->screen()->size());

    return { container, view, rootEntity };
}


int main(int argc, char * argv[])
{
    QApplication app(argc, argv);

    auto [container3d, view3d, rootEntity] = create3dView();

    QWidget * widget = new QWidget;
    QHBoxLayout * hLayout = new QHBoxLayout(widget);
    hLayout->addWidget(container3d);


    QQuickView * view = new QQuickView();
    view->setSource({"qrc:/main.qml"});

    QWidget * container = QWidget::createWindowContainer(view, container3d);
    //            container->setMinimumSize(...);
    //            container->setMaximumSize(...);





    //    view->registerAspect(new CustomAspect);

    Game::instance().init(rootEntity, view3d->camera());

    widget->setWindowTitle(QStringLiteral("Brain tennis"));
    widget->show();
    widget->resize(1200, 800);

    return app.exec();
}
