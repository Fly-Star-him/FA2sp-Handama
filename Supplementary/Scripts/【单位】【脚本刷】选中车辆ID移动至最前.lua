local section = "Units"
function moveToFront(t, i)
    if i < 1 or i > #t then
        return
    end
    local item = t[i]
    table.remove(t, i)
    table.insert(t, 1, item)
end

if running_lua_brush() then
	local cell = get_cell(X, Y)
	if cell.unit > -1 then
		local objs = get_values(section)
		moveToFront(objs, cell.unit+1)
		delete_section(section)	
		for i=1,#objs-1 do
			write_string(section, tostring(i-1), objs[i])
		end	
		update_unit()
	end
else
	message_box("���ű�����ͨ�����ű�ˢ�����У�", "����", 8)
end


