#### Layout

To activate Spanish keys either:
  a) In KDE/Gnome select "English (US, intl., with dead keys)"

  b) In console: ```shell
    /usr/share/X11/xkb/symbols/
    localectl list-x11-keymap-variants us

    setxkbmap us altgr-intl
    ```

