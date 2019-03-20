#ifndef PROGRESS_H
#define PROGRESS_H

#include <QDialog>
#include "ui_dialog.h"

class Progress : public QDialog, public Ui::Dialog {
Q_OBJECT

public:
    Progress( QWidget * parent = nullptr);

};

#endif // PROGRESS_H
