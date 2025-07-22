function calculate_mp_values(x1, y1, x2, y2, mapwidth, mapheight)
    local mpL = (mapwidth + y1 - x1 - 1) / 2
    local mpT = y1 - mpL + 2
    local sum_WH = y2 - mpT - mpL - 2
    local diff_HW = x2 - mapwidth - 1 - (mpT - mpL)
    local mpH = (sum_WH + diff_HW) / 2
    local mpW = sum_WH - mpH

    return math.ceil(mpL), math.floor(mpT), math.floor(mpW), math.floor(mpH)
end

if running_lua_brush() then
	if holding_click == false then
		if first_run then
			top_left_x = Y
			top_left_y = X
			print("��ʾ����ո�ѡ�������Ͻǣ���������ѡ�����½�")
		else
			bottom_right_x = Y
			bottom_right_y = X
			
			if top_left_y < bottom_right_y then
				local mpL, mpT, mpW, mpH = calculate_mp_values(top_left_x, top_left_y, bottom_right_x, bottom_right_y, width(), height())
				print("��ͼ�߽磨��,��,��,�ߣ���"..tostring(mpL)..","..tostring(mpT)..","..tostring(mpW)..","..tostring(mpH))
				print("��ʾ�����ڵ�ͼ�߶Ȼ�Ӱ����ʾ���뾡���ڴ�ƽ����ʾ������½���ѡ��")
			else
				print("���󣺱��밴�����Ͻ�->���½ǵ�˳��ѡ��")
			end
		end
	end
else
	message_box("���ű�����ͨ�����ű�ˢ�����У�", "����", 8)
end
