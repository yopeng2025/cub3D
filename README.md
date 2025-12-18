`git submodule add https://github.com/42Paris/minilibx-linux.git minilibx-linux`

`git commit -m "Add minilibx-linux as a git submodule"`

`git push origin main`

Git 会记录minilibx子模块链接和路径，但源码本身不会直接存到主仓库




`git submodule update --init --recursive`


改作业时，自动在 minilibx-linux 文件夹里拉取 MinilibX 源码
日常更新子模块
