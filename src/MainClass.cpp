#include "MainClass.h"
#include <QFile>

typedef struct my_struct{
    my_struct(const quint32 my_i, const bool my_b):i{my_i}, b{my_b}{};
    my_struct(){};
    quint32 i{};
    bool b{};
}my_struct_t;

QDataStream &operator<<(QDataStream &out, const my_struct_t& s){
    out << s.i << s.b;
    return out;
}

QDataStream &operator>>(QDataStream &in, my_struct_t& s){
    in >> s.i >> s.b;
    return in;
}

void MainClass::write(){
    my_struct_t obj(3, true);
    QFile file("file.dat");
    file.open(QIODevice::WriteOnly);
    QDataStream out(&file); // we will serialize the data into the file
    out << obj; // serialize a custom struct
}


void MainClass::read(){
    my_struct_t obj;
    QFile file("file.dat");
    file.open(QIODevice::ReadOnly);
    QDataStream in(&file); // read the data serialized from the file
    in >> obj; // extract 3 and true
    qDebug().noquote().nospace() << "obj.i=" << obj.i << " obj.b=" << obj.b;
}


MainClass::MainClass(QObject *parent)
    : QObject(parent)
{
    write();
    read();
}
