#ifndef RASTERISATION_H
#define RASTERISATION_H

#include <QtWidgets>

QT_BEGIN_NAMESPACE
namespace Ui { class Rasterisation; }
QT_END_NAMESPACE

class Rasterisation : public QMainWindow
{
    Q_OBJECT

public:
    Rasterisation(QWidget *parent = nullptr);
    ~Rasterisation();
    void MakeOsi();
    void UpdateLabel();
    void resizeEvent(QResizeEvent*);
    void DrawWuLine();
private slots:
    void on_horizontalSlider_valueChanged(int value);

    void on_spinBox_valueChanged(int arg1);

    void on_spinBox_2_valueChanged(int arg1);

    void on_spinBox_3_valueChanged(int arg1);

    void on_spinBox_4_valueChanged(int arg1);

    void DrawLine();

    void SetRange();

    void ChangeStart();

    void ChangeCdStart();

    void negatex(QPoint&);

    void negatey(QPoint&);

    void reflect(QPoint&);

    void ChangePoints();

    void ChangeWuPoints();

    void on_StepAlgorithm_clicked();

    void on_Bresenhem_clicked();

    void on_CDA_clicked();

    void on_radioButton_4_clicked();


    void on_spinBox_5_valueChanged(int arg1);

    QString reflect(QString&);

    void InitPoints();

    void on_Kastl_Pitway_clicked();

    void on_pushButton_clicked();

    QString to_number(const int&) const;

    QString to_float(const float&) const;
    void on_AlWu_clicked();

private:
    Ui::Rasterisation *ui;
    QPixmap* pixmap;
    int rate = 25;
    int r = 8;
    int xstart;
    int ystart;
    int xend;
    int yend;
    bool rotation;
    QPoint offset;
    int kx = 1, ky = 1;
    bool b, bc, s, cd, k, alwu;
    QVector<QPoint> points;
    QVector<QPair<QPoint, QColor> > WuPoints;
    QString info = "HAHAHHAHAH";
};
#endif // RASTERISATION_H
