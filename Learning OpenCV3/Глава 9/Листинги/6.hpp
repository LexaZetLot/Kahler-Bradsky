#ifndef QMOVIEPLAYER_HPP
#define QMOVIEPLAYER_HPP
#include "ui_qmovieplayer.hpp"
#include <QtWidgets/QtWidgets>
#include <opencv2/opencv.hpp>
#include <string>
using namespace std;
class QMoviePlayer : public QWidget {
    Q_OBJECT;
public:
    QMoviePlayer( QWidget *parent = NULL );
    virtual ~QMoviePlayer() {;}
    bool open( string file );
private:
    cv::VideoCapture m_cap;
    QImage  m_qt_img;
    cv::Mat m_cv_img;
    QTimer* m_timer;
    void paintEvent( QPaintEvent* q );
    void _copyImage( void );
public slots:
    void nextFrame();
};

#endif // QMOVIEPLAYER_HPP

