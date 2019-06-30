#include "mainwindow.h"

#include <QApplication>
#include <QPainter>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarSeries>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QHorizontalStackedBarSeries>
#include <QtCharts/QLineSeries>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>


QT_CHARTS_USE_NAMESPACE

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QBarSet *set0 = new QBarSet("Altuve");
    QBarSet *set1 = new QBarSet("Martinze");
    QBarSet *set2 = new QBarSet("Segura");
    QBarSet *set3 = new QBarSet("Simmons");
    QBarSet *set4 = new QBarSet("Trout");

    *set0 << 283 << 341 << 311 << 261 << 411 << 333;
    *set1 << 250 << 300 << 321 << 344 << 255 << 355;
    *set2 << 264 << 286 << 299 << 312 << 314 << 359;
    *set3 << 344 << 366 << 341 << 243 << 341 << 266;
    *set4 << 264 << 220 << 389 << 380 << 306 << 316;

    QHorizontalStackedBarSeries *series = new QHorizontalStackedBarSeries();
    series->append(set0);
    series->append(set1);
    series->append(set2);
    series->append(set3);
    series->append(set4);

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Batting Avg by Year");

    chart->setAnimationOptions(QChart::AllAnimations);
    QStringList categories;
    categories << "2013" << "2014" << "2015" << "2016" << "2017" << "2018";
    QBarCategoryAxis *axis = new QBarCategoryAxis();
    axis->append(categories);
    chart->createDefaultAxes();
    chart->setAxisY(axis, series);
    chart->legend()->setVisible(true);

    chart->legend()->setAlignment(Qt::AlignBottom);
    QChartView *chartView = new QChartView{chart};
    chartView->setRenderHint(QPainter::Antialiasing);
    QPalette palette = qApp->palette();
    palette.setColor(QPalette::Window, QRgb(0xffffff));
    palette.setColor(QPalette::WindowText, QRgb(0x404040));


    MainWindow w;

    w.setCentralWidget(chartView);
    w.resize(420, 300);
    w.show();

    return a.exec();
}
