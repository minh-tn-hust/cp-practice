#include <iostream>
#include <string>

class Person {
public:
    std::string ho_ten;
    std::string ngay_sinh;

    Person(std::string ho_ten, std::string ngay_sinh)
        : ho_ten(ho_ten), ngay_sinh(ngay_sinh) {}

    virtual void in_thong_tin() {
        std::cout << "Ho ten: " << ho_ten << ", Ngay sinh: " << ngay_sinh << std::endl;
    }
};

class SinhVien : public Person {
public:
    std::string ma_sinh_vien;

    SinhVien(std::string ho_ten, std::string ngay_sinh, std::string ma_sinh_vien)
        : Person(ho_ten, ngay_sinh), ma_sinh_vien(ma_sinh_vien) {}

    void in_thong_tin() override {
        std::cout << "Loai: Sinh vien" << std::endl;
        Person::in_thong_tin();
        std::cout << "Ma sinh vien: " << ma_sinh_vien << std::endl;
    }
};

class HocSinh : public Person {
public:
    std::string ma_hoc_sinh;

    HocSinh(std::string ho_ten, std::string ngay_sinh, std::string ma_hoc_sinh)
        : Person(ho_ten, ngay_sinh), ma_hoc_sinh(ma_hoc_sinh) {}

    void in_thong_tin() override {
        std::cout << "Loai: Hoc sinh" << std::endl;
        Person::in_thong_tin();
        std::cout << "Ma hoc sinh: " << ma_hoc_sinh << std::endl;
    }
};

class CongNhan : public Person {
public:
    std::string ma_cong_nhan;

    CongNhan(std::string ho_ten, std::string ngay_sinh, std::string ma_cong_nhan)
        : Person(ho_ten, ngay_sinh), ma_cong_nhan(ma_cong_nhan) {}

    void in_thong_tin() override {
        std::cout << "Loai: Cong nhan" << std::endl;
        Person::in_thong_tin();
        std::cout << "Ma cong nhan: " << ma_cong_nhan << std::endl;
    }
};

class NgheSi : public Person {
public:
    std::string nghe_danh;

    NgheSi(std::string ho_ten, std::string ngay_sinh, std::string nghe_danh)
        : Person(ho_ten, ngay_sinh), nghe_danh(nghe_danh) {}

    void in_thong_tin() override {
        std::cout << "Loai: Nghe si" << std::endl;
        Person::in_thong_tin();
        std::cout << "Nghe danh: " << nghe_danh << std::endl;
    }
};

class CaSi : public Person {
public:
    std::string ten_ca_si;

    CaSi(std::string ho_ten, std::string ngay_sinh, std::string ten_ca_si)
        : Person(ho_ten, ngay_sinh), ten_ca_si(ten_ca_si) {}

    void in_thong_tin() override {
        std::cout << "Loai: Ca si" << std::endl;
        Person::in_thong_tin();
        std::cout << "Ten ca si: " << ten_ca_si << std::endl;
    }
};

int main() {
    int lua_chon;
    std::cout << "Chon loai doi tuong (1: Sinh vien, 2: Hoc sinh, 3: Cong nhan, 4: Nghe si, 5: Ca si): ";
    std::cin >> lua_chon;

    std::string ho_ten, ngay_sinh, ma_sv, ma_hs, ma_cn, nghe_danh, ten_ca_si;

    std::cout << "Nhap ho ten: ";
    std::cin.ignore();  
    std::getline(std::cin, ho_ten);
    std::cout << "Nhap ngay sinh: ";
    std::cin >> ngay_sinh;

    Person* doi_tuong = nullptr;

    if (lua_chon == 1) {
        std::cout << "Nhap ma sinh vien: ";
        std::cin >> ma_sv;
        doi_tuong = new SinhVien(ho_ten, ngay_sinh, ma_sv);
    } else if (lua_chon == 2) {
        std::cout << "Nhap ma hoc sinh: ";
        std::cin >> ma_hs;
        doi_tuong = new HocSinh(ho_ten, ngay_sinh, ma_hs);
    } else if (lua_chon == 3) {
        std::cout << "Nhap ma cong nhan: ";
        std::cin >> ma_cn;
        doi_tuong = new CongNhan(ho_ten, ngay_sinh, ma_cn);
    } else if (lua_chon == 4) {
        std::cout << "Nhap nghe danh: ";
        std::cin >> nghe_danh;
        doi_tuong = new NgheSi(ho_ten, ngay_sinh, nghe_danh);
    } else if (lua_chon == 5) {
        std::cout << "Nhap ten ca si: ";
        std::cin.ignore();  
        std::getline(std::cin, ten_ca_si);
        doi_tuong = new CaSi(ho_ten, ngay_sinh, ten_ca_si);
    } else {
        std::cout << "Lua chon khong hop le." << std::endl;
        return 1;  
    }

    std::cout << "Thong tin doi tuong:\n";
    doi_tuong->in_thong_tin();

    delete doi_tuong;  
    return 0;
}