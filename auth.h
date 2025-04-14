#ifndef AUTH_H
#define AUTH_H

int authenticate_user(char* username, char* password);
int generate_2fa_code();

#endif // AUTH_H
