if running_lua_brush() then
	if holding_click == false then
		local cell = get_cell(X, Y)
		if first_run then
			tile_index = cell.tile
			subtile_index = cell.subtile
			message_box("��ո�ѡ����Դ���Σ����������Ŀ����Σ�ʵ���滻", "��ʾ", 0)
		else
			save_undo()
			local tile_index2 = cell.tile
			local subtile_index2 = cell.subtile
			local loop_cells = get_cells()
			for i,cell in pairs(loop_cells) do
				if cell.tile == tile_index2 and cell.subtile == subtile_index2 then
					cell.tile = tile_index
					cell.subtile = subtile_index
					cell:apply()
				end
			end
			save_redo()
		end
	end
else
	message_box("���ű�����ͨ�����ű�ˢ�����У�", "����", 8)
end
