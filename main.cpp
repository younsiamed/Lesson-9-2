#include <QCoreApplication>
#include <QTcpSocket>   // Для работы с сетью
#include <QSqlDatabase> // Для работы с базой данных
#include <QSqlError>    // Для обработки ошибок базы данных
#include <QDebug>

int main(int argc, char *argv[]) {
    QCoreApplication app(argc, argv);

    // Пример работы с сетью: создание TCP-сокета
    QTcpSocket socket;
    socket.connectToHost("example.com", 80); // Подключение к серверу
    if (socket.waitForConnected(3000)) {
        qDebug() << "TCP socket успешно подключен.";
        socket.disconnectFromHost();
    } else {
        qDebug() << "Ошибка подключения к серверу:" << socket.errorString();
    }

    // Пример работы с базой данных: подключение к SQLite
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(":memory:"); // База данных в памяти
    if (db.open()) {
        qDebug() << "SQLite база данных успешно открыта.";
        db.close();
    } else {
        qDebug() << "Ошибка подключения к базе данных:" << db.lastError().text();
    }

    return 0;
}
