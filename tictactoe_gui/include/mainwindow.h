#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "game.h"
#include <QPainter>
#include <QPen>
#include <QApplication>
#include <QMouseEvent>
#include <QMessageBox>

using namespace std;


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    /**
     * @brief paintEvent funkcja rysujaca plansze i znaki na planszy oraz tlo
     */
    void paintEvent(QPaintEvent *);
    /**
     * @brief mousePressEvent funkcja rejstrujace klikniecia myszy
     *
     * Funkcja dzieki, ktrej mozna stawiac znaki za pomoca myszy,
     * w jej wnetrzu przeprowadzone jest praktycznie cala rozgrywka
     * @param event
     */
    void mousePressEvent(QMouseEvent *event);

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    /**
     * @brief rozmiar funkcja okreslajaca i zwracajaca przez parametr
     * poczatkowy rozmiar planszy
     * @param N
     */
    void rozmiar(int &N);
    /**
     * @brief czygra funkcja nadajaca poczatkowe parametry kluczowym
     * zmiennym potrzebnym podczs dzialania programu - zmiennej pomocniczej
     * pom7 odpowiedzialnej za tury graczy oraz zmiennej gra mowiacej o
     * tym, ktory tryb gry  jest wybrany
     * @param k
     */
    void czygra(int k);
    /**
     * @brief x_m zmienne
     *
     * x_m y_m Zmienne, ktre okreslaja element tablicy, do ktorego ma byc wstawiony
     * element, po konwersji ze wspolrzednych klikniec myszki
     * x_AI y_AI zmienne okreslajace wspolrzedne ruchu komputera
     */
    int x_m,y_m,x_AI,y_AI;
    /**
     * @brief The Pos struct wspolrzedne ruchow (potrzebne przy cofaniu)
     */
    struct Pos{
        int x;
        int y;
    };
    /**
     * @brief undo_ tablica struktur (liczba el. tablicy to liczba komorek na
     * planszy, kazdemu dla kazdego ruchu zapisywane sa wspolrzedne)
     */
    Pos *undo_;
    /**
     * @brief newPos tworzy pierwsza tablice wspolrzednych
     */
    void newPos();

private slots:
    /**
     * @brief on_pbGraAI_clicked wybor gry z komputerem
     */
    void on_pbGraAI_clicked();
    /**
     * @brief on_pbGraPvP_clicked wybór gry PvP
     */
    void on_pbGraPvP_clicked();
    /**
     * @brief on_pbWstecz_clicked umozliwia cofanie ruchow, dla PvP po jednym ruchu
     * dla gry z komputerem cofa rucho gracza oraz komputera za jednym kliknieciem
     */
    void on_pbWstecz_clicked();

private:


    /**
     * @brief A_ tablica, w ktorej zawarte sa informacje o stanie gry (planszy)
     */
    char **A_;
    /**
     * @brief N_ rozmiar planszy - liczba kolumn/wierszy
     */
    int N_;
    /**
     * @brief gra zmienne potrzebne do przebiegu gry
     */
    int gra,pom7;



    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
