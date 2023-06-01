#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include <errno.h>
#include <stdarg.h>
#include <stdbool.h>

char board[3][3];
enum game_state
{
    GAMESTATE_UNDECIDED,
    GAMESTATE_DRAW,
    GAMESTATE_WINNER_PLAYER1,
    GAMESTATE_WINNER_PLAYER2
};

void init_board( char board[3][3] );
void print_board( char board[3][3] );
enum game_state evaluate_game_state( char board[3][3] );
int get_int_from_user( const char *prompt, ... );

int main( void )
{
    char board[3][3];
    bool first_players_turn = true;
    enum game_state gs;

    init_board( board );

    while ( ( gs = evaluate_game_state( board ) ) == GAMESTATE_UNDECIDED )
    {
        //prompt user for input until input is valid
        for (;;)
        {
            int input;

            print_board( board );

            input = get_int_from_user(
                "It is player %d's turn.\n"
                "Please select a move (1-9): ",
                first_players_turn ? 1 : 2
            );

            if ( 1 <= input && input <= 9 )
            {
                int x = ( input - 1 ) % 3;
                int y = ( input - 1 ) / 3;

                //make sure field is empty
                if ( board[y][x] != 'E' )
                {
                    printf( "That field is already occupied!\n\n" );
                    continue;
                }

                //perform the move
                board[y][x] = first_players_turn ? 'X' : 'O';
                first_players_turn = !first_players_turn;
                break;
            }

            printf( "Input must be between 1 and 9!\n\n" );
        }
    }

    //game is over

    print_board( board );

    switch ( gs )
    {
        case GAMESTATE_DRAW:
            printf( "The game is a draw.\n\n" );
            break;
        case GAMESTATE_WINNER_PLAYER1:
            printf( "Player 1 wins!\n\n" );
            break;
        case GAMESTATE_WINNER_PLAYER2:
            printf( "Player 2 wins!\n\n" );
            break;
    }
}

void init_board( char board[3][3] )
{
    for ( int i = 0; i < 3; i++ )
        for ( int j = 0; j < 3; j++ )
            board[i][j] = 'E';
}

void print_board( char board[3][3] )
{
    printf( "\n\n" );

    for ( int i = 0; i < 3; i++ )
    {
        for ( int j = 0; j < 3; j++ )
        {
            //add spacing if necessary
            if ( j != 0 )
                printf( " " );
            
            if ( board[i][j] == 'E' )
                //replace empty field with number of field
                printf( "%d", (i*3) + (j+1) );
            else
                printf( "%c", board[i][j] );
        }

        //end the line
        printf( "\n" );
    }

    printf( "\n" );
}

enum game_state evaluate_game_state( char board[3][3] )
{
    //check for horizontal wins
    for ( int i = 0; i < 3; i++ )
    {
        char possible_winner = board[i][0];

        if ( possible_winner != 'E' )
        {
            if ( possible_winner == board[i][1] && possible_winner == board[i][2] )
            {
                return possible_winner == 'X' ? GAMESTATE_WINNER_PLAYER1 : GAMESTATE_WINNER_PLAYER2;
            }
        }
    }

    //check for vertical wins
    for ( int i = 0; i < 3; i++ )
    {
        char possible_winner = board[0][i];

        if ( possible_winner != 'E' )
        {
            if ( possible_winner == board[1][i] && possible_winner == board[2][i] )
            {
                return possible_winner == 'X' ? GAMESTATE_WINNER_PLAYER1 : GAMESTATE_WINNER_PLAYER2;
            }
        }
    }

    //check for diagonal-down win
    {
        char possible_winner = board[0][0];

        if ( possible_winner != 'E' )
        {
            if ( possible_winner == board[1][1] && possible_winner == board[2][2] )
            {
                return possible_winner == 'X' ? GAMESTATE_WINNER_PLAYER1 : GAMESTATE_WINNER_PLAYER2;
            }
        }
    }

    //check for diagonal-up win
    {
        char possible_winner = board[2][0];

        if ( possible_winner != 'E' )
        {
            if ( possible_winner == board[1][1] && possible_winner == board[0][2] )
            {
                return possible_winner == 'X' ? GAMESTATE_WINNER_PLAYER1 : GAMESTATE_WINNER_PLAYER2;
            }
        }
    }

    //check if board is full
    for ( int i = 0; i < 3; i++ )
        for ( int j = 0; j < 3; j++ )
            if ( board[i][j] == 'E' )
                return GAMESTATE_UNDECIDED;

    return GAMESTATE_DRAW;
}

int get_int_from_user( const char *prompt, ... )
{
    for (;;) //loop forever until user enters a valid number
    {
        va_list args;
        char buffer[1024], *p;
        long l;

        //prompt user for input
        va_start( args, prompt );
        vprintf( prompt, args );
        va_end( args );

        //get one line of input from input stream
        if ( fgets( buffer, sizeof buffer, stdin ) == NULL )
        {
            fprintf( stderr, "unrecoverable error reading from input\n" );
            exit( EXIT_FAILURE );
        }

        //make sure that entire line was read in (i.e. that
        //the buffer was not too small)
        if ( strchr( buffer, '\n' ) == NULL && !feof( stdin ) )
        {
            int c;

            printf( "line input was too long!\n" );

            //discard remainder of line
            do
            {
                c = getchar();

                if ( c == EOF )
                {
                    fprintf( stderr, "unrecoverable error reading from input\n" );
                    exit( EXIT_FAILURE );
                }

            } while ( c != '\n' );

            continue;
        }

        //attempt to convert string to number
        errno = 0;
        l = strtol( buffer, &p, 10 );
        if ( p == buffer )
        {
            printf( "error converting string to number\n" );
            continue;
        }

        //make sure that number is representable as an "int"
        if ( errno == ERANGE || l < INT_MIN || l > INT_MAX )
        {
            printf( "number out of range error\n" );
            continue;
        }

        //make sure that remainder of line contains only whitespace,
        //so that input such as "6sdfh4q" gets rejected
        for ( ; *p != '\0'; p++ )
        {
            if ( !isspace( (unsigned char)*p ) )
            {
                printf( "unexpected input encountered!\n" );

                //cannot use `continue` here, because that would go to
                //the next iteration of the innermost loop, but we
                //want to go to the next iteration of the outer loop
                goto continue_outer_loop;
            }
        }

        return l;

    continue_outer_loop:
        continue;
    }
}