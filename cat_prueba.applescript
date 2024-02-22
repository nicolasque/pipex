repeat 5 times
  tell application "Terminal"
    activate
    do script "cat /dev/urandom"
  end tell
end repeat