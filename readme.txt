minilibx
1. 建立.gitmodules
2. 填充
	[submodule "minilibx-linux"]
	path = minilibx-linux
	url = https://github.com/42Paris/minilibx-linux.git
3. 提交作业时添加.gitmodules 不加minilibx-linux
4. 批改作业时 terminal输入:
	git submodule update --init --recursive
	直接克隆minilibx仓库
	
运行
   git submodule update --init --recursive
1. cd minilibx-linux
2. make
3. cd ..

4. make
5. ./Cub3D map/1.cub
6. valgrind ./Cub3D map/1.cub

7. make bonus
8. ./Cub3D_bonus map/1.cub
9. valgrind ./Cub3D_bonus map/1.cub

测评：
1. parse贴图， 地图
2. 修改颜色参数
3. 替换贴图
