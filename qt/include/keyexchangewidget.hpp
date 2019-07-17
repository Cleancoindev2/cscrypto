#ifndef KEY_EXCHANGE_WIDGET_HPP
#define KEY_EXCHANGE_WIDGET_HPP

#include <QString>
#include <QWidget>

#include <net.hpp>

class QHBoxLayout;
class QLabel;
class QLayout;
class QListView;
class QPushButton;
class QStatusBar;
class QSqlTableModel;
class QTableView;

namespace cscrypto {
namespace gui {

class KeyListModel;

class KeyExchangeWidget : public QWidget {
    Q_OBJECT

public:
    KeyExchangeWidget(QStatusBar& sb, KeyListModel* ownKeysModel,
                      QSqlTableModel& importedKeysModel, QWidget* parent = nullptr);

signals:
    void canSetUpSessionKey(bool);
    void canEnableIncomingConnections(bool);

private:
    void tuneLayout();
    void fillUpperLaytout(QHBoxLayout*);
    void fillLowLayout(QLayout*);

    void setOwnKey();
    void setHostName(const QString&);
    void inspectKeyIdText(const QString&);

    void enableIncomingConnections();
    void sendKeyExchangeRequest();
    void hostNameEnterDialog();
    void networkMessageHandler(const QString& msg);
    void newKeysHandler(QString b58SendSk, QString b58ReceiveSk);

    QStatusBar& statusBar_;
    KeyListModel* ownKeysModel_;
    QListView* ownKeysView_;
    QSqlTableModel& importedKeysModel_;
    QTableView* importedKeysView_;
    QLabel* ownKeySelectedLbl_;
    QLabel* importedKeySelectedLbl_;
    QPushButton* serverBtn_;

    QString importedKey_;
    QString hostName_;

    bool ownKeyOk_;
    bool importedKeyOk_;
    bool canEnableIncomingConnections_;

    Net network_;
};

} // namespace gui
} // namespace cscrypto
#endif // KEY_EXCHANGE_WIDGET_HPP