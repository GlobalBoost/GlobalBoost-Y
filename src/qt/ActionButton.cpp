    #include "ActionButton.h"
     
    ActionButton::ActionButton(QWidget *parent) :
        QPushButton(parent)
    {
        actionOwner = NULL;
        setFocusPolicy(Qt::NoFocus);
//        setIconSize(QSize(55,45));

    }
     
    void ActionButton::setAction(QAction *action)
    {
     
        // if I've got already an action associated to the button
        // remove all connections
     
        if( actionOwner != NULL && actionOwner != action ){
            disconnect( actionOwner,
                        SIGNAL(changed()),
                        this,
                        SLOT(updateButtonStatusFromAction()) );
     
            disconnect( this,
                        SIGNAL(clicked()),
                        actionOwner,
                        SLOT(trigger()) );
        }
     
     
        // store the action
        actionOwner = action;
     
        // configure the button
        updateButtonStatusFromAction();
     
     
     
        // connect the action and the button
        // so that when the action is changed the
        // button is changed too!
        connect( action,
                 SIGNAL(changed()),
                 this,
                 SLOT(updateButtonStatusFromAction()));
     
        // connect the button to the slot that forwards the
        // signal to the action
        connect( this,
                 SIGNAL(clicked()),
                 actionOwner,
                 SLOT(trigger()) );
    }
     
    void ActionButton::updateButtonStatusFromAction()
    {
//        setText( actionOwner->text() );
        setStatusTip( actionOwner->statusTip() );
        setToolTip( actionOwner->toolTip() );
        setIcon( actionOwner->icon() );
        setEnabled( actionOwner->isEnabled() );
        setCheckable( actionOwner->isCheckable() );
        setChecked( actionOwner->isChecked());
        setObjectName(actionOwner->property("objectName").toString());
     
    }

