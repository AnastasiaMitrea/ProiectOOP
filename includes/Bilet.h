#ifndef BILET_H
#define BILET_H

namespace Transport_Aerian {

    class Bilet {
    public:
        Bilet(); //constructor default
        Bilet(const std::string& id, const std::string& clasa, int pret); //constructor cu parametri

        std::string GetId() const;
        std::string GetClasa() const;
        int GetPret() const;
        void SetId(const std::string& id);
        void SetClasa(const std::string& clasa);
        void SetPret(int pret);

        friend std::ostream& operator<<(std::ostream& out, const Bilet& bilet); //supraincarcare << - afisare

    private:
        std::string m_id;
        std::string m_clasa;
        int m_pret;
    };

}

#endif
