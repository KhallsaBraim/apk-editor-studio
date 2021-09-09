#include "sheets/welcomesheet.h"
#include "base/application.h"
#include "windows/mainwindow.h"

WelcomeSheet::WelcomeSheet(MainWindow *mainWindow) : BaseActionSheet(mainWindow)
{
    btnOpen = addButton();
    btnInstall = addButton();
    btnExplorer = addButton();
    btnDonate = addButton();
    connect(btnOpen, &QPushButton::clicked, mainWindow, &MainWindow::openExternalApk);
    connect(btnInstall, &QPushButton::clicked, mainWindow, &MainWindow::installExternalApk);
    connect(btnExplorer, &QPushButton::clicked, mainWindow, [mainWindow]() {
        app->actions.openAndroidExplorer(mainWindow);
    });
    connect(btnDonate, &QPushButton::clicked, &app->actions, &ActionProvider::visitDonatePage);
}

void WelcomeSheet::changeEvent(QEvent *event)
{
    if (event->type() == QEvent::LanguageChange) {
        //: Don't translate the "APK Editor Studio" part.
        setTitle(tr("Welcome to the APK Editor Studio."));
        btnOpen->setText(tr("Open APK"));
        btnInstall->setText(tr("Install APK"));
        btnExplorer->setText(app->translate("AndroidExplorer", "Android Explorer"));
        btnDonate->setText(tr("Support Us"));
    }
    BaseActionSheet::changeEvent(event);
}