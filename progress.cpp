#include "progress.h"


Progress::Progress(QWidget * parent) :
    QDialog(parent)
{
    setupUi(this);
    this->setModal(true);
}
