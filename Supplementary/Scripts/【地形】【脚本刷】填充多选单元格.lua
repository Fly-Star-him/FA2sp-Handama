if running_lua_brush() then
	save_undo()
	local cell = get_cell(X, Y)
	local tile_index = cell.tile
	local subtile_index = cell.subtile
	for i,cell in pairs(get_multi_selected_cells()) do
		cell.tile = tile_index
		cell.subtile = subtile_index
		cell:apply()
	end
	save_redo()
else
	message_box("���ű�����ͨ�����ű�ˢ�����У�", "����", 8)
end
