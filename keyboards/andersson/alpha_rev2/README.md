# Andersson Alpha, rev 2

Source: <https://git.josf.dev/josefandersson/keyboard/src/branch/master/andersson_alpha/rev2>.

Uses homerow mods - <https://precondition.github.io/home-row-mods#using-home-row-mods-with-qmk>.

## Promicro

`qmk flash --keyboard andersson/alpha_rev2 --keymap default`

## Frood

Run with CONVERT_TO envvar!

`qmk flash --keyboard andersson/alpha_rev2 --keymap default -e CONVERT_TO=promicro_rp2040`
