#include "rasterisation.h"
#include "ui_rasterisation.h"
#include <ctime>
Rasterisation::Rasterisation(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Rasterisation)
{
    ui->setupUi(this);
    ui->label->resize(600, 600);
    pixmap = new QPixmap(ui->label->size());
    xstart = ystart = xend = yend = 0;
    pixmap->fill(Qt::white);
    ui->label->setMinimumSize(40, 40);
    ui->spinBox->setValue(0);
    ui->spinBox_2->setValue(0);
    ui->spinBox_3->setValue(0);
    ui->spinBox_4->setValue(0);
    ui->horizontalSlider->setRange(5, 30);
    ui->horizontalSlider->setValue(15);
    points.push_back(QPoint(0, 0));
    points.push_back(QPoint(0, 0));
    ui->spinBox_5->setValue(5);
    b = bc = cd = s = k = alwu = false;
    MakeOsi();
}

Rasterisation::~Rasterisation()
{
    delete ui;
}

void Rasterisation::MakeOsi()
{
    pixmap->fill(Qt::white);
    QPainter painter(pixmap);
    QPen pen;
    pen.setWidth(5);
    painter.setPen(pen);
    painter.drawLine(0, pixmap->height()/2, pixmap->width(), pixmap->height()/2);
    painter.drawLine(pixmap->width()/2, 0, pixmap->width()/2, pixmap->height());
    pen.setWidth(1);
    painter.setPen(pen);
    int w = pixmap->width() / rate;
    int h = pixmap->height() / rate;
    int hw = pixmap->width() / 2;
    int hh = pixmap->height()/2;
    for(int i = 1; i < w/2; i++)
    {
        painter.drawText(QPointF(hw + rate * i - 7, hh + 10), QString::number(i));
        painter.drawText(QPointF(hw - rate * i - 7, hh + 10), QString::number(-i));
        painter.drawLine(hw - rate * i, 0,hw -  rate * i, pixmap->height());
        painter.drawLine(hw + rate * i, 0,hw +  rate * i, pixmap->height());
    }
    for(int i = 1; i < h/2; i++)
    {
        painter.drawText(QPointF(hw - 14, hh + rate * i + 10), QString::number(-i));
        painter.drawText(QPointF(hw - 14, hh -  rate * i + 10), QString::number(i));
        painter.drawLine(0, hh - i * rate, pixmap->width(), hh - i * rate);
        painter.drawLine(0, hh + i * rate, pixmap->width(), hh + i * rate);
    }
    painter.drawText(QPointF(hw - 7, hh + 10), "0");
    painter.end();
    if(!alwu)
    {
        DrawLine();
    }
    else
    {
        DrawWuLine();
    }
    UpdateLabel();
    SetRange();
}

void Rasterisation::UpdateLabel()
{
    ui->label->setPixmap(*pixmap);
}

void Rasterisation::SetRange()
{
    int w = pixmap->width() / rate;
    int h = pixmap->height() / rate;
    ui->spinBox->setRange(-w/2, w/2);
    ui->spinBox_2->setRange(-h/2, h/2);
    ui->spinBox_3->setRange(-w/2, w/2);
    ui->spinBox_4->setRange(-h/2, h/2);
    int q = std::min(h/2, w/2);
    ui->spinBox_5->setRange(-q, q);
}

void Rasterisation::ChangeStart()
{
    rotation = false;
    kx = ky = 1;
    int x = points.first().x();
    int y = points.first().y();
    int dx = points.last().x() - x;
    int dy = points.last().y() - y;
    if(dx < 0)
    {
        kx = -1;
        negatex(points.first());
        negatex(points.last());
    }
    if(dy < 0)
    {
        ky = - 1;
        negatey(points.first());
        negatey(points.last());
    }
    if(abs(dy) > abs(dx))
    {
        rotation = true;
        reflect(points.first());
        reflect(points.last());
    }
    x = points.first().x();
    y = points.first().y();
    points.first().setX(0);
    points.first().setY(0);
    points.last().setX(points.last().x() - x);
    points.last().setY(points.last().y() - y);
    offset = QPoint(x, y);
}

void Rasterisation::ChangeCdStart()
{
    rotation = false;
    kx = ky = 1;
    int x = points.first().x();
    int y = points.first().y();
    int dx = points.last().x() - x;
    int dy = points.last().y() - y;
    if(dx < 0)
    {
        kx = -1;
        negatex(points.first());
        negatex(points.last());
    }
    if(dy < 0)
    {
        ky = - 1;
        negatey(points.first());
        negatey(points.last());
    }
    x = points.first().x();
    y = points.first().y();
    points.first().setX(0);
    points.first().setY(0);
    points.last().setX(points.last().x() - x);
    points.last().setY(points.last().y() - y);
    offset = QPoint(x, y);
}

void Rasterisation::negatex(QPoint & p)
{
    p.setX(-p.x());
}

void Rasterisation::negatey(QPoint & p)
{
    p.setY(-p.y());
}

void Rasterisation::reflect(QPoint & p)
{
    int q = p.x();
    p.setX(p.y());
    p.setY(q);
}

void Rasterisation::ChangePoints()
{
    for(int i = 0; i < points.size(); i++)
    {
        points[i].setX(points[i].x() + offset.x());
        points[i].setY(points[i].y() + offset.y());
        if(rotation)
        {
            reflect(points[i]);
        }
        if(ky == -1)
        {
            negatey(points[i]);
        }
        if(kx == -1)
        {
            negatex(points[i]);
        }
    }
}

void Rasterisation::ChangeWuPoints()
{
    for(int i = 0; i < WuPoints.size(); i++)
    {
        WuPoints[i].first.setX(WuPoints[i].first.x() + offset.x());
        WuPoints[i].first.setY(WuPoints[i].first.y() + offset.y());
        if(rotation)
        {
            reflect(WuPoints[i].first);
        }
        if(ky == -1)
        {
            negatey(WuPoints[i].first);
        }
        if(kx == -1)
        {
            negatex(WuPoints[i].first);
        }
    }
}

void Rasterisation::resizeEvent(QResizeEvent * e)
{
    *pixmap = pixmap->scaled(ui->label->size());
    MakeOsi();
    UpdateLabel();
    QMainWindow::resizeEvent(e);
}

void Rasterisation::DrawWuLine()
{
    QPainter painter(pixmap);
    QPen pen;
    pen.setWidth(0);
    painter.setPen(pen);
    QBrush brush;
    brush.setColor(Qt::black);
    painter.setBrush(Qt::black);
    for(QPair<QPoint, QColor> point: WuPoints)
    {
        painter.setBrush(point.second);
        painter.drawRect(pixmap->width() / 2 + point.first.x() * rate/* - rate/2*/, pixmap->height() / 2 + -point.first.y()*rate/* - rate/2*/, rate, rate);
    }
    UpdateLabel();
}


void Rasterisation::on_horizontalSlider_valueChanged(int value)
{
    rate = value;
    MakeOsi();
}

void Rasterisation::on_spinBox_valueChanged(int arg1)
{
    xstart = arg1;
    InitPoints();
    if(b)
    {
        on_Bresenhem_clicked();
    }
    if(cd)
    {
        on_CDA_clicked();
    }
    if(s)
    {
        on_StepAlgorithm_clicked();
    }
    if(bc)
    {
        on_radioButton_4_clicked();
    }
    if(k)
    {
        on_Kastl_Pitway_clicked();
    }
    if(alwu)
    {
        on_AlWu_clicked();
    }
    else
    {
        MakeOsi();
    }
}

void Rasterisation::on_spinBox_2_valueChanged(int arg1)
{
    ystart = arg1;
    InitPoints();
    if(b)
    {
        on_Bresenhem_clicked();
    }
    if(cd)
    {
        on_CDA_clicked();
    }
    if(s)
    {
        on_StepAlgorithm_clicked();
    }
    if(bc)
    {
        on_radioButton_4_clicked();
    }
    if(k)
    {
        on_Kastl_Pitway_clicked();
    }
    if(alwu)
    {
        on_AlWu_clicked();
    }
    else
    {
        MakeOsi();
    }
}

void Rasterisation::on_spinBox_3_valueChanged(int arg1)
{
    xend = arg1;
    InitPoints();
    if(b)
    {
        on_Bresenhem_clicked();
    }
    if(cd)
    {
        on_CDA_clicked();
    }
    if(s)
    {
        on_StepAlgorithm_clicked();
    }
    if(alwu)
    {
        on_AlWu_clicked();
    }
    if(bc)
    {
        on_radioButton_4_clicked();
    }
    if(k)
    {
        on_Kastl_Pitway_clicked();
    }
    else
    {
        MakeOsi();
    }
}

void Rasterisation::on_spinBox_4_valueChanged(int arg1)
{
    yend = arg1;
    InitPoints();
    if(b)
    {
        on_Bresenhem_clicked();
    }
    if(bc)
    {
        on_radioButton_4_clicked();
    }
    if(alwu)
    {
        on_AlWu_clicked();
    }
    if(cd)
    {
        on_CDA_clicked();
    }
    if(s)
    {
        on_StepAlgorithm_clicked();
    }
    if(k)
    {
        on_Kastl_Pitway_clicked();
    }
    else
    {
        MakeOsi();
    }
}

void Rasterisation::DrawLine()
{
    QPainter painter(pixmap);
    QPen pen;
    pen.setWidth(0);
    painter.setPen(pen);
    QBrush brush;
    brush.setColor(Qt::black);
    painter.setBrush(Qt::black);
    for(QPoint point: points)
    {
        painter.drawRect(pixmap->width() / 2 + point.x() * rate - rate/2, pixmap->height() / 2 + -point.y()*rate - rate/2, rate, rate);
    }
    UpdateLabel();
}

void Rasterisation::on_StepAlgorithm_clicked()
{
    info = "Имя алгоритма - Пошаговый алгоритм\n";
    InitPoints();
    int stime = clock();
    cd = bc = b = k = alwu = false;
    s = true;
    QPoint first = points.first();
    QPoint last = points.last();
    points.clear();
    float k;
    float x = first.x();
    float y = first.y();
    float xs = last.x();
    float ys = last.y();
    info += "Начальная точка: (" + to_number(x) + ", " + to_number(y) + ")\n";
    info += "Конечная точка: (" + to_number(xs) + ", " + to_number(ys) + ")\n";
    if(x == xs)
    {
        info += "Отрезок вертикальный(частный случай):\n";
        if(ys >= y)
        {
            for(int i = 0; i <= ys - y; i++)
            {
                points.push_back(QPoint(x, y + i));
                info += "Добавляем точку (" + to_number(x) + ", " + to_number(y + i) + ")\n";
            }
        }
        else
        {
            for(int i = 0; i <= y - ys; i++)
            {
                points.push_back(QPoint(x, y - i));
                info += "Добавляем точку (" + to_number(x) + ", " + to_number(y + i) + ")\n";
            }
        }
    }
    else
    {
        k = float(ys - y) / float(xs - x);
        info += "Коэффициент k = " + QString::number(double(k)) + "\n";
        float b = y - k * x;
        info += "Коэффициент b = " + QString::number(double(b)) + "\n";
        points.push_back(QPoint(x, y));
        if(abs(xs - x) >= abs(ys - y))
        {
            info += "Рассматриваем относительно х(из соображений округления)\n";
            kx = 1;
            if(x > xs)
            {
                kx = -1;
            }
            while(x != xs)
            {
                x += kx;
                y = k * x + b;
                points.push_back(QPoint(x, y));
                info += "Точка (" + to_number(x) + ", " + to_float(y) + "), округление";
                info += "Добавляем точку (" + to_number(x) + ", " + to_number(y) + ")\n";
            }
        }
        else
        {
            info += "Рассматриваем относительно y(из соображений округления)\n";
            ky = 1;
            if(y > ys)
            {
                ky = -1;
            }
            while(y != ys)
            {
                y += ky;
                x = (y - b)/k;
                points.push_back(QPoint(x, y));
                info += "Точка (" + to_float(x) + ", " + to_number(y) + "), округление";
                info += "Добавляем точку (" + to_number(x) + ", " + to_number(y) + ")\n";
            }
        }
    }
    stime = clock() - stime;
    info += "Время выполнения: " + to_number(stime) + " миллисекунд";
    MakeOsi();
}

void Rasterisation::on_Bresenhem_clicked()
{
    info = "Имя Алгоритма - алгоритм Брезенхема\n";
    InitPoints();
    int stime = clock();
    cd = bc = s = k = alwu = false;
    int x, y;
    x = points.first().x();
    y = points.first().y();
    info += "Начальная точка: (" + to_number(x) + ", " + to_number(y) + ")\n";
    //info += "Конечная точка: (" + to_number(xs) + ", " + to_number(ys) + ")\n";
    info += "Преобразуем к первому октанту\n";
    ChangeStart();
    int dx, dy, ie, nie, e;
    dx = points.last().x() - points.first().x();
    dy = points.last().y() - points.first().y();
    e = 2 * dy - dx;
    ie = 2 * dy;
    nie = ie - 2 * dx;
    x = points.first().x();
    y = points.first().y();
    info += "Преобразованная начальная точка: (" + to_number(x) + ", " + to_number(y) + ")\n";
    info += "dx = " + to_number(dx) + ", dy = " + to_number(dy) + "\n";
    points.clear();
    int count = dx;
    points.push_back(QPoint(x, y));
    while(count > 0)
    {
        count--;
        if(e > 0)
        {
            info += "e > 0 -> увеличиваем у и x\n";
            y++;
            e += nie;
        }
        else
        {
            info += "e <= 0 увеличиваем x\n";
            e += ie;
        }
        x++;
        points.push_back(QPoint(x, y));
        info += "Добавляем точку (" + to_number(x) + ", " + to_number(y) + ")\n";
    }
    info += "Преобразуем точки обратно\n";
    ChangePoints();
    b = true;
    stime = clock() - stime;
    info += "Время выполнения: " + to_number(stime) + " миллисекунд";
    MakeOsi();
}

void Rasterisation::on_CDA_clicked()
{
    info = "Имя алгоритма - ЦДА алгоритм\n";
    InitPoints();
    int stime = clock();
    b = s = bc = k = alwu = false;
    cd = true;
    float x, y;
    x = points.first().x();
    y = points.first().y();
    info += "Начальная точка: (" + to_number(x) + ", " + to_number(y) + ")\n";
    info += "Преобразуем к первому-второму октантам\n";
    ChangeCdStart();
    float dx, dy;
    dx = points.last().x() - points.first().x();
    dy = points.last().y() - points.first().y();
    int l = std::max(dx, dy);
    x = points.first().x();
    y = points.first().y();
    info += "Преобразованная начальная точка: (" + to_number(x) + ", " + to_number(y) + "\n";
    info += "dx = " + to_float(dx) + ", dy = " + to_float(dy) + "\n";
    points.clear();
    points.push_back(QPoint(x, y));
    int i = 0;
    while(i < l)
    {
        y += dy / l;
        x += dx / l;
        i++;
        info += "Полученная точка : (" + to_float(x) + ", " + to_float(y) + "), округление\n";
        points.push_back(QPoint(x, y));
        info += "Добавляем точку (" + to_number(x) + ", " + to_number(y) + ")\n";
    }
    info += "Меняем точки обратно\n";
    ChangePoints();
    stime = clock() - stime;
    info += "Время выполнения: " + to_number(stime) + " миллисекунд";
    MakeOsi();
}

void Rasterisation::on_radioButton_4_clicked()
{
    info = "Имя алгоритма - Алгоритм Брезенхема для окружности\n";
    info += "При добавлении точки добавляются 4 точки с координатами, различными знаком\n";
    InitPoints();
    int stime = clock();
    b = cd = s = k = alwu = false;
    bc = true;
    QPoint offset = points.first();
    info += "Середина окружности: (" + to_number(offset.x()) + ", " + to_number(offset.y()) + ")\n";
    info += "Перемещаем середину в начало координат\n";
    points.first().setX(0);
    points.first().setY(0);
    int x = 0, y = r;
    info += "Радиус = " + to_number(r) + "\n";
    int e = 3 - 2 * r;
    info += "Величина шага = " + to_number(e);
    points.clear();
    points.push_back(QPoint(x, y));
    points.push_back(QPoint(-x, y));
    points.push_back(QPoint(x, -y));
    points.push_back(QPoint(-x, -y));
    info += "Добавляем точку (" + to_number(x) + ", " + to_number(y) + ")\n";
    points.push_back(QPoint(y, x));
    points.push_back(QPoint(-y, x));
    points.push_back(QPoint(y, -x));
    points.push_back(QPoint(-y, -x));
    info += "Добавляем точку (" + to_number(y) + ", " + to_number(x) + ")\n";
    while (x < y)
    {
        if (e <= 0)
        {
            info += "Величина шага <= 0 -> увеличиваем x\n";
            e += 2 * x + 3;
        }
        else
        {
            info += "Величина шага > 0 -> увеличиваем x, уменьшаем y\n";
            e += 2 * (x - y) + 5;
            y--;
        }
        x++;
        // Добавляем новые точки
        points.push_back(QPoint(x, y));
        points.push_back(QPoint(-x, y));
        points.push_back(QPoint(x, -y));
        points.push_back(QPoint(-x, -y));
        info += "Добавляем точку (" + to_number(x) + ", " + to_number(y) + ")\n";
        points.push_back(QPoint(y, x));
        info += "Добавляем точку (" + to_number(y) + ", " + to_number(x) + ")\n";
        points.push_back(QPoint(-y, x));
        points.push_back(QPoint(y, -x));
        points.push_back(QPoint(-y, -x));
    }
    info += "Перемещаем середину окружности\n";
    for(int i = 0; i < points.size(); i++)
    {
        points[i].setX(points[i].x() + offset.x());
        points[i].setY(points[i].y() + offset.y());
    }
    stime = clock() - stime;
    info += "Время выполнения: " + to_number(stime) + " миллисекунд";
    MakeOsi();
}

void Rasterisation::on_spinBox_5_valueChanged(int arg1)
{
    r =arg1;
    if(bc)
    {
        on_radioButton_4_clicked();
    }
}

QString Rasterisation::reflect(QString& s)
{
    QString r = "";
    for(int i = 0; i < s.size(); i++)
    {
        r.push_front(s[i]);
    }
    return r;
}

void Rasterisation::InitPoints()
{
    points.clear();
    points.push_back(QPoint(xstart, ystart));
    points.push_back(QPoint(xend, yend));
}

void Rasterisation::on_Kastl_Pitway_clicked()
{
    info = "Имя алгоритма - алгоритм Кастла-Питвея\n";
    s = b = bc = cd = alwu = false;
    InitPoints();
    int stime = clock();
    ChangeStart();
    info += "Преобразуем к первому октанту\n";
    int x, y;
    x = points.first().x();
    y = points.last().y();
    info += "Начальная точка: (" + to_number(x) + ", " + to_number(y) + ")\n";
    x = points.last().x();
    y = points.last().y();
    info += "Конечная точка: (" + to_number(x) + ", " + to_number(y) + ")\n";
    info += "Конечная точка: (" + to_number(x) + ", " + to_number(y) + ")\n";
    y = points.last().y();
    x = points.last().x() - y;
    info += "x = " + to_number(x) + "\n";
    info += "y = " + to_number(y) + "\n";
    int qz = 1;
    QString m1 = "s", m2 = "d";
    if(points.first().y() == y)
    {
        info += "Отрезок горизонтальный\n";
        x = points.first().x();
        y = points.last().y();
        int c = points.last().x() - x;
        points.clear();
        for(int q = 0; q < c; q++)
        {
            points.push_back(QPoint(x, y));
            info += "Добавляем точку (" + to_number(x) + ", " + to_number(y) + ")\n";
            x++;
            info += "Увеличиваем x\n";
        }
    }
    else if(points.first().x() == points.last().x())
    {
        info += "Отрезок вертикальный\n";
        x = points.first().x();
        y = points.last().y();
        int c = points.last().y() - y;
        points.clear();
        for(int q = 0; q < c; q++)
        {
            points.push_back(QPoint(x, y));
            info += "Добавляем точку (" + to_number(x) + ", " + to_number(y) + ")\n";
            y++;
            info += "Увеличиваем y\n";
        }
    }
    else if(x == 0)
    {
        info += "Отрезок диагональный";
        x = points.first().x();
        y = points.first().y();
        int c = points.last().x() - x;
        points.clear();
        for(int q = 0; q <= c; q++)
        {
            points.push_back(QPoint(x, y));
            info += "Добавляем точку (" + to_number(x) + ", " + to_number(y) + ")\n";
            x++;
            y++;
            info += "Увеличиваем x и y\n";
        }
    }
    else
    {
        while(x != y)
        {
            if(x > y)
            {
                x -= y;
                info += "x > y -> m2 = m1 + !(m2)\n";
                m2 = m1 + reflect(m2);
                info += "m2 = " + m2 + "\n";
            }
            else
            {
                y -= x;
                info += "x <= y -> m1 = m2 + !(m1)";
                m1 = m2 + reflect(m1);
                info += "m1 = " + m1 + "\n";
            }
        }
        m1 = m2 + reflect(m1);
        info += "Последовательность = " + m1 + "\n";
        qz = x;
        x = points.first().x();
        y = points.first().y();
        points.clear();
        points.push_back(QPoint(x, y));
        for(int q = 0; q < qz; q++)
        {
            for(int i = 0; i < m1.size(); i++)
            {
                x++;
                if(m1[i] == 'd')
                {
                    y++;
                    info += "Диагональное смещение -> увеличиваем x и y\n";
                }
                else
                {
                    info += "Горизонтальное смещение -> увеличиваем x\n";
                }
                points.push_back(QPoint(x, y));
                info += "Добавляем точку (" + to_number(x) + ", " + to_number(y) + ")\n";
            }
        }
    }
    k = true;
    info += "Преобразуем точки обратно\n";
    ChangePoints();
    stime = clock() - stime;
    info += "Время выполнения: " + to_number(stime) + " миллисекунд";
    MakeOsi();
}

void Rasterisation::on_pushButton_clicked()
{
    QDialog qd(this);
    QVBoxLayout* qv = new QVBoxLayout(&qd);
    qv->addWidget(new QLabel(info, &qd));
    qd.exec();
}

QString Rasterisation::to_number(const int & n) const
{
    return QString::number(n);
}

QString Rasterisation::to_float(const float & f) const
{
    return QString::number(f);
}

void Rasterisation::on_AlWu_clicked()
{
    info = "Имя алгоритма - Алгоритм Ву\n";
    InitPoints();
    WuPoints.clear();
    k = cd = b = bc = false;
    alwu = true;
    int x, y;
    x = points.first().x();
    y = points.first().y();
    info += "Начальная точка: (" + to_number(x) + ", " + to_number(y) + ")\n";
    int stime = clock();
    info += "Преобразуем точки к первому октанту\n";
    ChangeStart();
    int N = 256;
    QColor gray;
    gray = Qt::black;
    info += "Концы отрезка - чёрный цвет";
    WuPoints.push_back(QPair<QPoint, QColor>(points[0], gray));
    WuPoints.push_back(QPair<QPoint, QColor>(points[1], gray));
    int M = 256;
    x = y = 0;
    int c = points.last().x() - x;
    int i = 0;
    if(points.first().x() == points.last().x())
    {
        info += "Вертикальный отрезок\n";
        x = points.first().x();
        y = points.first().y() + 1;
        c = points.last().y() - y;
        while(c > 1)
        {
            c--;
            WuPoints.push_back(QPair<QPoint, QColor>(QPoint(x, y), gray));
            info += "Добавили точку (" + to_number(x) + ", " + to_number(y) + ")\n";
            y++;
            info += "Увеличили y\n";
        }
    }
    else if(points.first().y() == points.last().y())
    {
        info += "Горизонтальный отрезок\n";
        x = points.first().x() + 1;
        y = points.first().y();
        while(c > 1)
        {
            c--;
            WuPoints.push_back(QPair<QPoint, QColor>(QPoint(x, y), gray));
            info += "Добавили точку (" + to_number(x) + ", " + to_number(y) + ")\n";
            x++;
            info += "Увеличили x\n";
        }
    }
    else if(points.last().x() == points.last().y())
    {
        info += "Диагональный отрезок\n";
        x = points.first().x() + 1;
        y = points.first().y() + 1;
        while(c > 1)
        {
            c--;
            WuPoints.push_back(QPair<QPoint, QColor>(QPoint(x, y), gray));
            info += "Добавили точку (" + to_number(x) + ", " + to_number(y) + ")\n";
            x++;
            y++;
            info += "Увеличили x\n";
            info += "Увеличили y\n";
        }
    }
    else
    {
        int xe = points.last().x();
        int ye = points.last().y();
        x = points.first().x();
        y = points.first().y();
        int step = (points.last().y() * N)/points.last().x();
        while(x < xe)
        {
            x++;
            xe--;
            i += step;
            if(i >= N)
            {
                y++;
                ye--;
                i-=N;
            }
            gray.setCmyk(0, 0, 0, i * M / N);
            WuPoints.push_back(QPair<QPoint, QColor>(QPoint(x, y), gray));
            info += "Добавили точку (" + to_number(x) + ", " + to_number(y) + ")\n";
            WuPoints.push_back(QPair<QPoint, QColor>(QPoint(xe, ye), gray));
            info += "Добавили точку (" + to_number(xe) + ", " + to_number(ye) + ")\n";
            gray.setCmyk(0, 0, 0, M - 1 - gray.black());
            WuPoints.push_back(QPair<QPoint, QColor>(QPoint(x, y + 1), gray));
            info += "Добавили точку (" + to_number(x) + ", " + to_number(y + 1) + ")\n";
            WuPoints.push_back(QPair<QPoint, QColor>(QPoint(xe, ye - 1), gray));
            info += "Добавили точку (" + to_number(xe) + ", " + to_number(ye - 1) + ")\n";
        }
    }
    info += "Преобразуем точки обратно\n";
    ChangeWuPoints();
    stime = clock() - stime;
    info += "Время выполнения: " + to_number(stime) + " миллисекунд";
    MakeOsi();
}
