namespace hellmath {

// TODO: Task 1 - Define an `AccountStatus` enumeration to represent the four
// account types: `troll`, `guest`, `user`, and `mod`.
enum AccountStatus {
    troll,
    guest,
    user,
    mod
};
// TODO: Task 1 - Define an `Action` enumeration to represent the three
// permission types: `read`, `write`, and `remove`.
enum Action {
    read,
    write,
    remove
};

// TODO: Task 2 - Implement the `display_post` function, that gets two arguments
// of `AccountStatus` and returns a `bool`. The first argument is the status of
// the poster, the second one is the status of the viewer.
bool display_post(AccountStatus poster_status, AccountStatus viewer_status) {
    bool is_display{};
    switch (poster_status) {
        case AccountStatus::troll:
            is_display = poster_status == viewer_status;
            break;
        default:
            is_display = true;
            break;
    }

    return is_display;
}

// TODO: Task 3 - Implement the `permission_check` function, that takes an
// `Action` as a first argument and an `AccountStatus` to check against. It
// should return a `bool`.
bool permission_check(Action action, AccountStatus account_status) {
    bool permission{false};
    switch (account_status) {
        case AccountStatus::guest:
            permission = action == Action::read;
            break;
        case AccountStatus::troll:
        case AccountStatus::user:
            permission = action == Action::read || action == Action::write;
            break;
        default:
            permission = true;
            break;
    };

    return permission;
}
    
// TODO: Task 4 - Implement the `valid_player_combination` function that
// checks if two players can join the same game. The function has two parameters
// of type `AccountStatus` and returns a `bool`.
bool valid_player_combination(AccountStatus status_player1, AccountStatus status_player2) {
    bool combination{false};
    if (status_player1 == AccountStatus::guest || status_player2 == AccountStatus::guest) {
        combination = false;
    } else if (status_player1 == AccountStatus::troll) {
        switch (status_player2) {
            case AccountStatus::troll:
                combination = true;
                break;
            default:
                combination = false;
                break;
        }
    } else if (status_player2 == AccountStatus::troll) {
        switch (status_player1) {
            case AccountStatus::troll:
                combination = true;
                break;
            default:
                combination = false;
                break;
        }
    } else {
        combination = true;
    }

    return combination;
}
    
// TODO: Task 5 - Implement the `has_priority` function that takes two
// `AccountStatus` arguments and returns `true`, if and only if the first
// account has a strictly higher priority than the second.
bool has_priority(AccountStatus status_player1, AccountStatus status_player2) {
    bool priority{false};
    switch (status_player1) {
        case AccountStatus::mod:
            switch (status_player2) {
                case AccountStatus::mod:
                    priority = false;
                    break;
                default:
                    priority = true;
                    break;
            }
            break;

        case AccountStatus::user:
            switch (status_player2) {
                case AccountStatus::mod:
                case AccountStatus::user:
                    priority = false;
                    break;
                default:
                    priority = true;
                    break;
            }
            break;

        case AccountStatus::guest:
            switch (status_player2) {
                case AccountStatus::mod:
                case AccountStatus::user:
                case AccountStatus::guest:
                    priority = false;
                    break;
                default:
                    priority = true;
                    break;
            }
            break;

        default:
            priority = false;
            break;
        
    }

    return priority;
}
    
}  // namespace hellmath
