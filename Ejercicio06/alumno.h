#ifndef ALUMNO_H
#define ALUMNO_H

class alumno
{
private:
    char* nombre;
    long legajo;
    bool is_repeat_name;

    char* cfgName(const char* src);

public:
    alumno();

    alumno(const char* n, long l);

    alumno(const alumno& r_al);

    void setNombre(const char* n);

    void setLegajo(long l);

    char* getNombre() const;

    long getLegajo() const;

    alumno& operator=(const char* name);

    alumno& operator=(long l);

    alumno& operator=(const alumno& r_al);

    ~alumno();
};

#endif // ALUMNO_H
