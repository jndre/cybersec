//command and control server as described in Advanced Penetration Testing

#include <libssh/libssh.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
    ssh_session my_ssh_session;
    int rc;

    char *password = "password";
    int port = 443;

    my_ssh_session = ssh_new();
    if (my_ssh_session == NULL)
    {
        fprintf(stderr, "ssh_new failed");
    }

    ssh_options_set(my_ssh_session, SSH_OPTIONS_HOST, "c2host");
    ssh_options_set(my_ssh_session, SSH_OPTIONS_PORT, &port);
    ssh_options_set(my_ssh_session, SSH_OPTIONS_USER, "c2user");

    rc = ssh_connect(my_ssh_session);

    // deprecated
    // if(verify_knownhost(my_ssh_session) < 0){
    //     fprintf(stderr, "verify_knownhost failed");
    //     ssh_disconnect(my_ssh_session);
    //     ssh_free(my_ssh_session);
    //     exit(-1);
    // }

    rc = ssh_userauth_password(my_ssh_session, NULL, password);

    ssh_disconnect(my_ssh_session);
    ssh_free(my_ssh_session);
}
