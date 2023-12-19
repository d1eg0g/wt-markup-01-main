#include<iostream>

int main() {
    short int x, y, z, b, f;
    std::cout << "x = "; std::cin >> x;
    std::cout << "y = "; std::cin >> y;
    std::cout << "z = "; std::cin >> z;
    std::cout << "b = "; std::cin >> b;

    _asm {
        // Block of condition checks
        cmp x, 5
        jg m1
        cmp y, 0
        je m3
        jmp m2

    m1: // F = 3 * x + 2 * z + 5
        mov ax, x
        imul ax, 3
        mov bx, z
        imul bx, 2
        add ax, bx
        add ax, 5
        jmp stop

    m2: // F = 7 * y - 7 + 6 * x / z
        cmp z, 0
        je m3
        mov ax, y
        imul ax, 7
        sub ax, 7
        mov bx, x
        imul bx, 6
        cdq
        idiv z
        add ax, y
        jmp stop

    m3: // F = z + 3 * x
        mov ax, z
        add ax, x
        jmp stop

    stop:
        mov f, ax
    }

    std::cout << "F = " << f << std::endl;
    return 0;
}
