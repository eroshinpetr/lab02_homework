# Отчет по лабораторной работе №2
## Системы контроля версий на примере Git
**Студент:** Eroshin Petr  
**Дата выполнения:** 17.03.2026

## 1. Подготовка и настройка
### 1.1 Настройка переменных окружения
export GITHUB_USERNAME="eroshinpetr"
export GITHUB_EMAIL="[eroshinpetr1@gmail.com]"
echo $GITHUB_USERNAME
echo $GITHUB_EMAIL

Листинг вывода:
eroshinpetr
[eroshinpetr1@gmail.com]

1.2 Настройка Git
it config --global user.name "eroshinpetr"
git config --global user.email "[eroshinpetr1@gmail.com]"
git config --global --list

Листинг вывода:
user.name=eroshinpetr
user.email=[eroshinpetr1@gmail.com]

1.3 Создание репозитория
mkdir -p ~/eroshinpetr/workspace/projects/lab02_homework
cd ~/eroshinpetr/workspace/projects/lab02_homework
git init
echo "# Lab02 Homework" > README.md
git add README.md
git commit -m "first commit"
git branch -M main
git remote add origin https://github.com/eroshinpetr/lab02_homework.git
git push -u origin main

Листинг вывода:
Initialized empty Git repository in /home/xxxxx/eroshinpetr/workspace/projects/lab02_homework/.git/
[master (root-commit) 6504aa9] first commit
 1 file changed, 1 insertion(+)
 create mode 100644 README.md
Enumerating objects: 3, done.
Counting objects: 100% (3/3), done.
Writing objects: 100% (3/3), 215 bytes | 215.00 KiB/s, done.
Total 3 (delta 0), reused 0 (delta 0), pack-reused 0
To https://github.com/eroshinpetr/lab02_homework.git
 * [new branch]      main -> main
branch 'main' set up to track 'origin/main'.

2. Домашнее задание Part I

2.1 Создание hello_world.cpp с плохим стилем
cat > hello_world.cpp << 'EOF'
#include <iostream>
using namespace std;

int main() {
    cout << "Hello, World!" << endl;
    return 0;
}
EOF
cat hello_world.cpp

Листинг вывода:
#include <iostream>
using namespace std;

int main() {
    cout << "Hello, World!" << endl;
    return 0;
}

2.2 Добавление и коммит
git add hello_world.cpp
git commit -m "Add hello world program (bad style)"
git push

Листинг вывода:
[main 5af0731] Add hello world program (bad style)
 1 file changed, 7 insertions(+)
 create mode 100644 hello_world.cpp
Enumerating objects: 4, done.
Counting objects: 100% (4/4), done.
Delta compression using up to 3 threads
Compressing objects: 100% (3/3), done.
Writing objects: 100% (3/3), 395 bytes | 395.00 KiB/s, done.
Total 3 (delta 0), reused 0 (delta 0), pack-reused 0
To https://github.com/eroshinpetr/lab02_homework.git
   6504aa9..5af0731  main -> main

2.3 Изменение программы (запрос имени)
cat > hello_world.cpp << 'EOF'
#include <iostream>
#include <string>
using namespace std;

int main() {
    string name;
    cout << "Enter your name: ";
    getline(cin, name);
    cout << "Hello world from @" << name << endl;
    return 0;
}
EOF
cat hello_world.cpp

Листинг вывода:
#include <iostream>
#include <string>
using namespace std;

int main() {
    string name;
    cout << "Enter your name: ";
    getline(cin, name);
    cout << "Hello world from @" << name << endl;
    return 0;
}

git commit -am "Modify program to ask for user name"
git push

Листинг вывода:
[main 9e0ba91] Modify program to ask for user name
 1 file changed, 5 insertions(+), 1 deletion(-)
Enumerating objects: 5, done.
Counting objects: 100% (5/5), done.
Delta compression using up to 3 threads
Compressing objects: 100% (3/3), done.
Writing objects: 100% (3/3), 442 bytes | 442.00 KiB/s, done.
Total 3 (delta 0), reused 0 (delta 0), pack-reused 0
To https://github.com/eroshinpetr/lab02_homework.git
   5af0731..9e0ba91  main -> main

3. Домашнее задание Part II

3.1 Создание ветки patch1
git checkout -b patch1
git branch

Листинг вывода:
Switched to a new branch 'patch1'
  main
* patch1

3.2 Исправление кода (убираем using namespace std)
cat > hello_world.cpp << 'EOF'
#include <iostream>
#include <string>

int main() {
    std::string name;
    std::cout << "Enter your name: ";
    std::getline(std::cin, name);
    std::cout << "Hello world from @" << name << std::endl;
    return 0;
}
EOF
cat hello_world.cpp
git commit -am "Remove 'using namespace std;'"
git push -u origin patch1

Листинг вывода:
#include <iostream>
#include <string>

int main() {
    std::string name;
    std::cout << "Enter your name: ";
    std::getline(std::cin, name);
    std::cout << "Hello world from @" << name << std::endl;
    return 0;
}

[patch1 87fa42e] Remove 'using namespace std;'
 1 file changed, 4 insertions(+), 5 deletions(-)
Enumerating objects: 5, done.
Counting objects: 100% (5/5), done.
Delta compression using up to 3 threads
Compressing objects: 100% (3/3), done.
Writing objects: 100% (3/3), 433 bytes | 433.00 KiB/s, done.
Total 3 (delta 0), reused 0 (delta 0), pack-reused 0
remote: 
remote: Create a pull request for 'patch1' on GitHub by visiting:
remote:      https://github.com/eroshinpetr/lab02_homework/pull/new/patch1
remote: 
To https://github.com/eroshinpetr/lab02_homework.git
 * [new branch]      patch1 -> patch1
branch 'patch1' set up to track 'origin/patch1'.

3.3 Добавление комментариев
cat > hello_world.cpp << 'EOF'
#include <iostream>
#include <string>

int main() {
    std::string name;  // variable to store user name
    
    // Request user name
    std::cout << "Enter your name: ";
    std::getline(std::cin, name);
    
    // Print greeting
    std::cout << "Hello world from @" << name << std::endl;
    return 0;
}
EOF
cat hello_world.cpp
git commit -am "Add comments to code"
git push

Листинг вывода:
#include <iostream>
#include <string>

int main() {
    std::string name;  // variable to store user name
    
    // Request user name
    std::cout << "Enter your name: ";
    std::getline(std::cin, name);
    
    // Print greeting
    std::cout << "Hello world from @" << name << std::endl;
    return 0;
}
[вывод коммита и пуша]

3.4 Слияние Pull Request и удаление ветки
# На GitHub был создан и смёржен Pull Request #1
git checkout main
git pull
git branch -d patch1
git branch

Листинг вывода:
Switched to branch 'main'
Your branch is up to date with 'origin/main'.
...
Deleted branch patch1 (was [хеш]).
* main

4. Домашнее задание Part III

4.1 Установка и применение clang-format
sudo apt install clang-format -y
clang-format --version
git checkout -b patch2
clang-format -style=Mozilla -i hello_world.cpp
cat hello_world.cpp

Листинг вывода:
[версия clang-format]
...
#include <iostream>
#include <string>

int
main()
{
    std::string name; // variable to store user name

    // Request user name
    std::cout << "Enter your name: ";
    std::getline(std::cin, name);

    // Print greeting
    std::cout << "Hello world from @" << name << std::endl;
    return 0;
}

4.2 Коммит и push ветки patch2
git commit -am "Apply clang-format with Mozilla style"
git push -u origin patch2

4.3 Создание конфликта в main
git checkout main
cat > hello_world.cpp << 'EOF'
#include <iostream>
#include <string>

int main() {
    std::string name;  // variable to store user name
    
    // Request user name
    std::cout << "Enter your name: ";
    std::getline(std::cin, name);
    
    // Print greeting
    std::cout << "Hello world from @" << name << std::endl;
    return 0;
}
EOF
git commit -am "Change comments language to English"
git push

4.4 Разрешение конфликта через rebase
git checkout patch2
git pull --rebase origin main
# Возникает конфликт
cat > hello_world.cpp << 'EOF'
#include <iostream>
#include <string>

int
main()
{
    std::string name; // variable to store user name

    // Request user name
    std::cout << "Enter your name: ";
    std::getline(std::cin, name);

    // Print greeting
    std::cout << "Hello world from @" << name << std::endl;
    return 0;
}
EOF
git add hello_world.cpp
git rebase --continue
git push --force-with-lease

4.5 Финальное слияние и очистка
# На GitHub был создан и смёржен Pull Request #2
git checkout main
git pull
git branch -d patch2
git branch -a

Листинг вывода:
* main
  remotes/origin/main

5. Итоговая проверка

5.1 Финальная версия программы
cat hello_world.cpp

Листинг вывода:
#include <iostream>
#include <string>

int
main()
{
    std::string name; // variable to store user name

    // Request user name
    std::cout << "Enter your name: ";
    std::getline(std::cin, name);

    // Print greeting
    std::cout << "Hello world from @" << name << std::endl;
    return 0;
}

5.2 История коммитов
git log --oneline --graph --all

Листинг вывода:
*   0db5954 (HEAD -> main, origin/main) Resolve merge conflict: combine Mozilla style with English comments
|\  
| *   5c713b9 Merge pull request #2 from eroshinpetr/patch2
| |\  
| | * 8c92c32 Apply clang-format with Mozilla style
| |/  
* / 71ade00 Change comments language to English
|/  
*   73178ca Merge pull request #1 from eroshinpetr/patch1
|\  
| * 7bf60df Add comments to code
| * 87fa42e Remove 'using namespace std;'
|/  
* 9e0ba91 Modify program to ask for user name
* 5af0731 Add hello world program (bad style)
* 6504aa9 first commit

6. Выводы

В ходе выполнения лабораторной работы были изучены основные возможности системы контроля версий Git:

    Создание и клонирование репозиториев (git init, git clone)

    Добавление и коммит изменений (git add, git commit)

    Работа с ветками (git branch, git checkout, git merge)

    Синхронизация с удаленным репозиторием (git push, git pull)

    Разрешение конфликтов при слиянии веток

    Использование rebase для обновления веток

    Работа с Pull Request на GitHub

    Автоматическое форматирование кода с помощью clang-format

Ссылка на репозиторий: https://github.com/[eroshinpetr]/lab02_homework
