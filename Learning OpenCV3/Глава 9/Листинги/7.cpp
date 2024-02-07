#include "QMoviePlayer.hpp"
#include <QtCore/QTimer>
#include <QtGui/QPainter>
#include <QtWidgets/QtWidgets>
QMoviePlayer::QMoviePlayer( QWidget *parent )
    : QWidget( parent )
{
    ui.setupUi( this );
}

